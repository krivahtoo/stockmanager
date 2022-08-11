/*
 * Copyright (c) 2021 Noah Too
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "stock_manager.h"
#include "database.h"
#include "settings.h"
#include "structs.h"
#include "utils.h"

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>
#include <sqlcipher/sqlite3.h>

#include <QtCore/QCryptographicHash>
#include <QtCore/QDateTime>
#include <QtCore/QTimer>
#include <QtGui/QContextMenuEvent>
#include <QtGui/QKeySequence>
#include <QtWidgets/QAction>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QShortcut>

stock_manager::stock_manager(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::stock_manager) {
  // Setup all dialogs uis
  ui_dlg_search.setupUi(&dlg_search);
  ui_dlg_settings.setupUi(&dlg_settings);
  ui_dlg_edit.setupUi(&dlg_edit);
  ui_dlg_edit_sale.setupUi(&dlg_edit_sale);
  m_ui->setupUi(this);

  actEdit = new QAction(this);
  actEdit_Sale = new QAction(this);
  actDelete = new QAction(this);
  actDelete_Sale = new QAction(this);

  this->stockCount = 0;
  this->lastChange = 0;
  this->timerActive = false;
  m_ui->dateStart->setDate(QDate::currentDate().addDays(-10));
  m_ui->dateStart->setMaximumDate(QDate::currentDate());
  m_ui->dateEnd->setDate(QDate::currentDate());
  m_ui->dateEnd->setMaximumDate(QDate::currentDate());

  QShortcut *cartShortcut = new QShortcut(QKeySequence("Ctrl+1"), this);
  QShortcut *salesShortcut = new QShortcut(QKeySequence("Ctrl+2"), this);
  QShortcut *stockShortcut = new QShortcut(QKeySequence("Ctrl+3"), this);

  // Connect all slots
  connect(m_ui->btnSell_Cart, &QPushButton::pressed, this,
          &stock_manager::sellItems);
  connect(ui_dlg_edit.btnUpdate, &QPushButton::pressed, this,
          &stock_manager::updateItem);
  connect(ui_dlg_edit_sale.btnUpdate, &QPushButton::pressed, this,
          &stock_manager::updateSoldItem);
  connect(m_ui->actQt_About, &QAction::triggered, this, QApplication::aboutQt);
  connect(m_ui->actQuit, &QAction::triggered, this, &QCoreApplication::quit);
  connect(m_ui->actBackup_Database, &QAction::triggered, this,
          &stock_manager::backupDb);
  connect(actEdit, &QAction::triggered, this, &stock_manager::editSelectedItem);
  connect(actEdit_Sale, &QAction::triggered, this, [&]() {
    ui_dlg_edit_sale.dateTimeSale->setMaximumDateTime(
        QDateTime::currentDateTime());
    editSelectedSoldItem();
  });
  connect(actDelete, &QAction::triggered, this, &stock_manager::deleteItem);
  connect(actDelete_Sale, &QAction::triggered, this,
          &stock_manager::deleteSoldItem);
  connect(m_ui->dateStart, &QDateEdit::dateChanged, this,
          [&]() { m_ui->dateEnd->setMinimumDate(m_ui->dateStart->date()); });
  connect(m_ui->dateEnd, &QDateEdit::dateChanged, this,
          [&]() { m_ui->dateStart->setMaximumDate(m_ui->dateEnd->date()); });
  connect(ui_dlg_settings.btnChangePass, &QPushButton::pressed, this,
          &stock_manager::changePassword);
  connect(m_ui->tblStock, &QTableWidget::customContextMenuRequested, this,
          &stock_manager::editContext);
  connect(m_ui->tblSales, &QTableWidget::customContextMenuRequested, this,
          &stock_manager::editSaleContext);
  connect(m_ui->btnRefreshSales, &QPushButton::pressed, this,
          [&]() { updateSales(); });
  connect(m_ui->btnClear_Cart, &QPushButton::pressed, this, [&]() {
    cart.clear();
    updateCart();
  });
  connect(cartShortcut, &QShortcut::activated, this,
          [&]() { m_ui->tabMain->setCurrentIndex(0); });
  connect(salesShortcut, &QShortcut::activated, this,
          [&]() { m_ui->tabMain->setCurrentIndex(1); });
  connect(stockShortcut, &QShortcut::activated, this,
          [&]() { m_ui->tabMain->setCurrentIndex(2); });
  connect(m_ui->btnAdd_Cart, &QPushButton::pressed, this, [&]() {
    dlgAddNew *dlg_add_new = new dlgAddNew(this, cart);
    connect(dlg_add_new, &QDialog::accepted, this, [&]() { updateCart(); });
    dlg_add_new->show();
  });
  connect(m_ui->btnAddItem, &QPushButton::pressed, this, [&]() {
    dlgAdd *dlg_add = new dlgAdd(this);
    connect(dlg_add, &QDialog::accepted, this, [&]() {
      refreshDb();
      updateTable();
      updateStats();
    });
    dlg_add->show();
  });
  connect(m_ui->btnRefresh, &QPushButton::pressed, this, [&]() {
    refreshDb();
    updateTable();
    updateStats();
  });
  connect(m_ui->actSettings_2, &QAction::triggered, this,
          [&]() { dlg_settings.show(); });
  connect(m_ui->actionSearch, &QAction::triggered, this,
          [&]() { dlg_search.show(); });
  connect(m_ui->actAbout, &QAction::triggered, this, [&]() {
    dlgAbout *dlg_about = new dlgAbout(this);
    dlg_about->show();
  });
  connect(m_ui->actAccount, &QAction::triggered, this, [&]() {
    dlgAccount *dl_account = new dlgAccount(this);
    dl_account->show();
  });
  connect(m_ui->actHome, &QAction::triggered, this,
          [&]() { m_ui->tabMain->setCurrentIndex(0); });
  connect(m_ui->actSales, &QAction::triggered, this,
          [&]() { m_ui->tabMain->setCurrentIndex(1); });
  connect(m_ui->actStock, &QAction::triggered, this,
          [&]() { m_ui->tabMain->setCurrentIndex(2); });

  // Load all initial data
  refreshDb();
  updateTable();
  updateStats();
  updateSales();
  updateSalesStats();
}

void stock_manager::refreshDb() {
  using namespace sqlite_orm;
  this->setCursor(Qt::BusyCursor);
  items.clear();
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  auto allItems = storage->select(
      columns(&Item::id, &Item::itemNo, &Item::name, &Item::price,
              &Item::capacity, &Stock::quantity),
      where(c(&Item::itemNo) == &Stock::itemNo), order_by(&Item::id));

  for (auto &itm : allItems) {
    items.push_back(Items{
        std::get<0>(itm), // id
        std::get<1>(itm), // itemNo
        std::get<2>(itm), // Name
        std::get<3>(itm), // Price
        std::get<4>(itm), // capacity
        std::get<5>(itm)  // quantity
    });
  }
  this->unsetCursor();
}

void stock_manager::updateTable() {
  int count = 0;
  this->stockCount = 0;
  m_ui->tblStock->clearContents();
  m_ui->tblStock->setRowCount(items.size());
  for (const auto &itm : items) {
    QTableWidgetItem *tblItem1 = new QTableWidgetItem();
    tblItem1->setText(QString::fromStdString(itm.itemNo));
    m_ui->tblStock->setItem(count, 0, tblItem1);

    QTableWidgetItem *tblItem2 = new QTableWidgetItem();
    tblItem2->setText(QString::fromStdString(itm.name));
    m_ui->tblStock->setItem(count, 1, tblItem2);

    QTableWidgetItem *tblItem3 = new QTableWidgetItem();
    tblItem3->setText(QString::fromStdString(
        util::formatCurrency(util::formatNumber(itm.price))));
    m_ui->tblStock->setItem(count, 2, tblItem3);

    QTableWidgetItem *tblItem4 = new QTableWidgetItem();
    tblItem4->setText(QString::fromStdString(itm.capacity));
    m_ui->tblStock->setItem(count, 3, tblItem4);

    QTableWidgetItem *tblItem5 = new QTableWidgetItem();
    tblItem5->setText(QString::number(itm.quantity));
    m_ui->tblStock->setItem(count, 4, tblItem5);

    this->stockCount += itm.quantity;

    count++;
  }
}

void stock_manager::updateStats() {
  json data = getStatsData();
  QString stats_template = "<html><head/><body>";

  if (data.contains("stock"))
    stats_template.push_back(QString::fromStdString(inja::render(
        "<p>Stock: {{ stock.count }} of {{ stock.items }} items</p>", data)));

  if (data.contains("sales"))
    stats_template.push_back(QString::fromStdString(inja::render(
        "<p>Sales Today: {{ sales.count }} for {{ sales.price }}</p>", data)));

  if (data.contains("items") || data["items"].size() > 0)
    stats_template.push_back(QString::fromStdString(inja::render(R"(
<p>
  <span style=" font-weight:600;">Items Out of Stock:</span>
</p>
<p>
## for item in items
{{ loop.index1 }}: {{ item }}<br/>
## endfor
</p>)",
                                                                 data)));
  stats_template.push_back("</body></html>");

  m_ui->lblStats->setText(stats_template);
}

// TODO: refactor
json stock_manager::getStatsData() {
  using namespace sqlite_orm;
  json j;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  j["stock"]["items"] = storage->count<Stock>();
  j["stock"]["count"] = this->stockCount;

  QDateTime date_time = QDateTime::currentDateTime();
  date_time.setTime(QTime::fromString("00:00:00", "HH:mm:ss"));

  long int timestamp = date_time.toSecsSinceEpoch();

  auto sales = storage->select(columns(&Item::price, &SoldItem::quantity),
                               where(c(&Item::itemNo) == &SoldItem::itemNo and
                                     c(&SoldItem::saleDate) >= timestamp));

  int count = 0;
  long price = 0;

  for (auto &sale : sales) {
    price += std::get<0>(sale) * std::get<1>(sale);
    count += std::get<1>(sale);
  }

  j["sales"]["count"] = count;
  j["sales"]["price"] = util::formatCurrency(util::formatNumber(price));

  auto items = storage->select(
      columns(&Item::name, &Stock::quantity),
      where(c(&Item::itemNo) == &Stock::itemNo and c(&Stock::quantity) < 1));

  for (auto &itm : items) {
    // Limit items. Too much items breaks the ui.
    // TODO: use scroll view to enable showing more items.
    if (j["items"].size() < 20)
      j["items"].push_back(std::get<0>(itm));
  }
  return j;
}

void stock_manager::updateCart() {
  json j;
  int count = 0;
  long totalPrice = 0;
  m_ui->tblCart->clearContents();
  m_ui->tblCart->setRowCount(this->cart.size());
  for (auto &itm : this->cart) {
    QTableWidgetItem *tblItem1 = new QTableWidgetItem();
    tblItem1->setText(QString::fromStdString(itm.itemNo));
    m_ui->tblCart->setItem(count, 0, tblItem1);

    QTableWidgetItem *tblItem2 = new QTableWidgetItem();
    tblItem2->setText(QString::fromStdString(itm.name));
    m_ui->tblCart->setItem(count, 1, tblItem2);

    QTableWidgetItem *tblItem3 = new QTableWidgetItem();
    tblItem3->setText(QString::fromStdString(
        util::formatCurrency(util::formatNumber(itm.price))));
    m_ui->tblCart->setItem(count, 2, tblItem3);

    QTableWidgetItem *tblItem4 = new QTableWidgetItem();
    tblItem4->setText(QString::number(itm.quantity));
    m_ui->tblCart->setItem(count, 3, tblItem4);

    QTableWidgetItem *tblItem5 = new QTableWidgetItem();
    tblItem5->setText(QString::fromStdString(
        util::formatCurrency(util::formatNumber(itm.totalPrice))));
    totalPrice += itm.totalPrice;
    m_ui->tblCart->setItem(count, 4, tblItem5);

    count++;
  }
  j["count"] = count;
  j["total"] = util::formatCurrency(util::formatNumber(totalPrice));
  m_ui->lblItem_Count->setText(QString::fromStdString(inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style="font-size:12pt;">Items On Cart: {{ count }}</span>
        </p>
    </body>
</html>)",
                                                                   j)));
  m_ui->lblTotal->setText(QString::fromStdString(inja::render(R"(
<html>
    <head/>
    <body>
    <p><span style="font-size:16pt;">Total: {{ total }}</span></p>
    </body>
</html>)",
                                                              j)));
}

void stock_manager::sellItems() {
  using namespace sqlite_orm;
  // Don't even try when cart is empty
  if (this->cart.empty()) {
    QMessageBox::warning(this, "Cart Empty", "Cannot sell an empty cart");
    this->statusBar()->showMessage("Cart empty!", 2000);
    return;
  }
  this->setCursor(Qt::BusyCursor);
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  long int date = QDateTime::currentSecsSinceEpoch();
  std::string payment_method =
      this->m_ui->cmbPayment_Method->currentText().toStdString();
  int items_count = 0;

  try {
    auto guard = storage->transaction_guard();
    for (auto &itm : this->cart) {
      storage->insert(SoldItem{
          -1, itm.itemNo, itm.quantity, payment_method, date,
          std::make_unique<long>(itm.price),
          std::make_unique<int>(Settings::getInstance().getUser()->id)});
      auto items = storage->get_all_pointer<Stock>(
          where(c(&Stock::itemNo) == itm.itemNo));

      storage->update_all(
          set(c(&Stock::quantity) = items[0]->quantity - itm.quantity),
          where(c(&Stock::itemNo) == itm.itemNo));
      items_count++;
    }
    guard.commit();
    this->cart.clear();
  } catch (std::system_error &e) {
    std::cout << e.what() << std::endl;
    this->unsetCursor();
    this->statusBar()->showMessage("Oops, something went wrong", 2000);
    return;
  } catch (...) {
    std::cout << "Unknown Error occurred." << std::endl;
    this->unsetCursor();
    this->statusBar()->showMessage("Oops, something went wrong", 2000);
    return;
  }
  this->updateCart();
  this->unsetCursor();
  this->statusBar()->showMessage(QString("%1 Items sold").arg(items_count),
                                 2000);
}

void stock_manager::updateSales() {
  using namespace sqlite_orm;
  long start, end;
  json j;
  QDateTime date;
  // Avoid reloading too much
  if ((QDateTime::currentSecsSinceEpoch() - this->lastChange) <= 2 &&
      this->lastChange > 0) {
    if (!this->timerActive) {
      QTimer::singleShot(
          (QDateTime::currentSecsSinceEpoch() - this->lastChange) * 1000, this,
          [&]() { updateSales(); });
      this->timerActive = true;
    }
    return;
  }
  this->setCursor(Qt::BusyCursor);
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  date.setDate(m_ui->dateStart->date());
  date.setTime(QTime::fromString("00:00:00", "HH:mm:ss"));
  start = date.toSecsSinceEpoch();
  date.setDate(m_ui->dateEnd->date());
  date.setTime(QTime::fromString("23:59:59", "HH:mm:ss"));
  end = date.toSecsSinceEpoch();

  auto items = storage->select(
      columns(&SoldItem::id, &Item::name, &SoldItem::quantity,
              &SoldItem::sellingPrice, &SoldItem::paymentMethod,
              &SoldItem::saleDate, &Item::buyingPrice, &Item::price,
              &SoldItem::userId),
      where(c(&Item::itemNo) == &SoldItem::itemNo and
            c(&SoldItem::saleDate) >= start and c(&SoldItem::saleDate) <= end));

  int count = 0;
  int quantity = 0;
  long salesMade = 0;
  this->m_ui->tblSales->clearContents();
  this->m_ui->tblSales->setRowCount(items.size());

  for (auto &itm : items) {

    long price = *(std::get<3>(itm));
    if (price < std::get<7>(itm)) {
      if (price <= std::get<6>(itm)) {
        price = std::get<7>(itm);
      }
    }

    // SoldItem::id
    QTableWidgetItem *tblItem0 = new QTableWidgetItem();
    tblItem0->setText(QString::number(std::get<0>(itm)));
    m_ui->tblSales->setItem(count, 0, tblItem0);

    // Item::name
    QTableWidgetItem *tblItem1 = new QTableWidgetItem();
    tblItem1->setText(QString::fromStdString(std::get<1>(itm)));
    m_ui->tblSales->setItem(count, 1, tblItem1);

    // SoldItem::quantity
    QTableWidgetItem *tblItem2 = new QTableWidgetItem();
    tblItem2->setText(QString::number(std::get<2>(itm)));
    m_ui->tblSales->setItem(count, 2, tblItem2);
    quantity += std::get<2>(itm);

    // Item::price
    QTableWidgetItem *tblItem3 = new QTableWidgetItem();
    tblItem3->setText(QString::fromStdString(
        util::formatCurrency(util::formatNumber(price))));
    m_ui->tblSales->setItem(count, 3, tblItem3);

    // Total price
    QTableWidgetItem *tblItem4 = new QTableWidgetItem();
    tblItem4->setText(QString::fromStdString(
        util::formatCurrency(util::formatNumber(price * std::get<2>(itm)))));
    m_ui->tblSales->setItem(count, 4, tblItem4);

    // SoldItem::paymentMethod
    QTableWidgetItem *tblItem5 = new QTableWidgetItem();
    tblItem5->setText(QString::fromStdString(std::get<4>(itm)));
    m_ui->tblSales->setItem(count, 5, tblItem5);

    // SoldItem::saleDate
    QDateTime date_time = QDateTime::fromSecsSinceEpoch(std::get<5>(itm));
    QTableWidgetItem *tblItem6 = new QTableWidgetItem();
    tblItem6->setText(date_time.toString("dd MMM yyyy"));
    m_ui->tblSales->setItem(count, 6, tblItem6);

    // SoldItem::userId
    QTableWidgetItem *tblItem7 = new QTableWidgetItem();
    int *userId = std::get<8>(itm).get();
    tblItem7->setText("Unknown");
    if (userId != nullptr) {
      if (auto usr = storage->get_pointer<User>(*userId)) {
        tblItem7->setText(QString::fromStdString(usr->name));
      }
    }
    m_ui->tblSales->setItem(count, 7, tblItem7);

    salesMade += price * std::get<2>(itm);
    count++;
  }
  j["count"] = quantity;
  j["sales"] = util::formatCurrency(util::formatNumber(salesMade));
  j["start"] =
      m_ui->dateStart->date().toString("ddd dd MMMM yyyy").toStdString();
  j["end"] = m_ui->dateEnd->date().toString("ddd dd MMM yyyy").toStdString();
  this->m_ui->lblSalesStats->setText(QString::fromStdString(inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style="font-size:12pt;">Sales Made from </span>
            <span style="font-size:12pt; font-weight:600;">{{ start }}</span>
            <span style="font-size:12pt;"> to </span>
            <span style="font-size:12pt; font-weight:600;">{{ end }}</span>
        </p>
        <p>
            <span style="font-size:12pt;">Items Sold: </span>
            <span style="font-size:12pt; font-weight:600;">{{ count }}</span>
        </p>
        <p>
            <span style="font-size:12pt;">Sales Made: </span>
            <span style="font-size:12pt; font-weight:600;">{{ sales }}</span>
        </p>
    </body>
</html>)",
                                                                         j)));
  this->updateSalesStats();
  this->lastChange = QDateTime::currentSecsSinceEpoch();
  this->timerActive = false;
  this->unsetCursor();
}

void stock_manager::updateSalesStats() {
  using namespace sqlite_orm;
  json j;
  QDate dt;
  QDateTime date;
  long wStart, mStart, wEnd, mEnd;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  date.setDate(m_ui->dateStart->date());
  date.setTime(QTime::fromString("23:59:59", "HH:mm:ss"));

  // get the start of the week
  dt = date.date();
  dt = dt.addDays(-(dt.dayOfWeek() - 1));
  date = dt.startOfDay();
  wStart = date.toSecsSinceEpoch();
  // get the end of the week
  dt = dt.addDays(6);
  date = dt.endOfDay();
  wEnd = date.toSecsSinceEpoch();

  // get the start of the month
  dt = m_ui->dateStart->date();
  dt.setDate(dt.year(), dt.month(), 1);
  date = dt.startOfDay();
  mStart = date.toSecsSinceEpoch();
  // get the end of the month
  dt = dt.addDays(dt.daysInMonth() - 1);
  date = dt.endOfDay();
  mEnd = date.toSecsSinceEpoch();

  auto wItems =
      storage->select(columns(&SoldItem::quantity, &Item::price,
                              &SoldItem::sellingPrice, &Item::buyingPrice),
                      where(c(&Item::itemNo) == &SoldItem::itemNo and
                            c(&SoldItem::saleDate) >= wStart and
                            c(&SoldItem::saleDate) <= wEnd));
  int w_count = 0;
  int w_sales = 0;
  for (auto &itm : wItems) {
    long price = *(std::get<2>(itm));
    if (price < std::get<1>(itm)) {
      if (price <= std::get<3>(itm)) {
        price = std::get<1>(itm);
      }
    }
    w_count += std::get<0>(itm);
    w_sales += price * std::get<0>(itm);
  }
  j["w_count"] = w_count;
  j["w_sales"] = util::formatCurrency(util::formatNumber(w_sales));

  auto mItems =
      storage->select(columns(&SoldItem::quantity, &Item::price,
                              &SoldItem::sellingPrice, &Item::buyingPrice),
                      where(c(&Item::itemNo) == &SoldItem::itemNo and
                            c(&SoldItem::saleDate) >= mStart and
                            c(&SoldItem::saleDate) <= mEnd));
  int m_count = 0;
  int m_sales = 0;
  for (auto &itm : mItems) {
    long price = *(std::get<2>(itm));
    if (price < std::get<1>(itm)) {
      if (price <= std::get<3>(itm)) {
        price = std::get<1>(itm);
      }
    }
    m_count += std::get<0>(itm);
    m_sales += price * std::get<0>(itm);
  }
  j["m_count"] = m_count;
  j["m_sales"] = util::formatCurrency(util::formatNumber(m_sales));

  m_ui->lblSalesStats_2->setText(QString::fromStdString(inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style=" font-weight:600;">Week Sales:</span><br/>
            {{ w_count }} items for <span style=" font-weight:600;">{{ w_sales }}</span>
        </p>
        <p>
            <span style=" font-weight:600;">Month Sales:</span><br/>
            {{ m_count }} items for <span style=" font-weight:600;">{{ m_sales }}</span>
        </p>
    </body>
</html>)",
                                                                     j)));
}

void stock_manager::updateItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };

  Item item;
  try {
    auto item_old = storage->get_all_pointer<Item>(where(
        c(&Item::itemNo) == this->ui_dlg_edit.txtId->text().toStdString()));
    item.id = item_old[0]->id;
    item.itemNo = this->ui_dlg_edit.txtId->text().toStdString();
    item.name = this->ui_dlg_edit.txtName->text().toStdString();
    item.capacity = this->ui_dlg_edit.txtCapacity->text().toStdString();
    item.buyingPrice = this->ui_dlg_edit.spnBuyingPrice->cleanText().toLong();
    item.price = this->ui_dlg_edit.spnSellingPrice->cleanText().toLong();
    item.minimumPrice =
        this->ui_dlg_edit.spnMinimumSellingPrice->cleanText().toLong();

    // Update item
    storage->update(item);

    // Update stock item
    storage->update_all(
        set(c(&Stock::itemNo) = this->ui_dlg_edit.txtId->text().toStdString(),
            c(&Stock::quantity) =
                this->ui_dlg_edit.spnQuantity->cleanText().toInt()),
        where(c(&Stock::itemNo) = item.itemNo));
    this->dlg_edit.accept();
  } catch (...) {
    // Error 😜
    this->statusBar()->showMessage("Oops, something went wrong", 2000);
  }
}

void stock_manager::updateSoldItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  SoldItem sold_itm;
  int id = this->ui_dlg_edit_sale.lblId->text().toInt();
  sold_itm.id = id;
  sold_itm.itemNo = this->ui_dlg_edit_sale.txtId->text().toStdString();
  sold_itm.quantity = this->ui_dlg_edit_sale.spnQuantity->cleanText().toInt();
  sold_itm.paymentMethod =
      this->ui_dlg_edit_sale.cmbPayment_Method->currentText().toStdString();
  sold_itm.sellingPrice = std::make_unique<long>(
      this->ui_dlg_edit_sale.spnSale_Price->cleanText().toLong());
  sold_itm.saleDate =
      this->ui_dlg_edit_sale.dateTimeSale->dateTime().toSecsSinceEpoch();

  storage->update(sold_itm);
  this->dlg_edit_sale.accept();
}

void stock_manager::deleteItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  QTableWidgetItem *tblItem = this->m_ui->tblStock->selectedItems().first();
  std::string itemNo =
      this->m_ui->tblStock->item(tblItem->row(), 0)->text().toStdString();
  auto itm = storage->get_all_pointer<Item>(where(c(&Item::itemNo) == itemNo));
  int ret =
      QMessageBox::warning(this, "Stock Manager",
                           QString("Are you sure you want to delete %1 ?")
                               .arg(QString::fromStdString(itm[0]->name)),
                           QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

  switch (ret) {
  case QMessageBox::Yes:
    // Delete from db
    storage->remove<Item>(itm[0]->id);
    this->statusBar()->showMessage("Item deleted succefully.", 2000);
    break;
  case QMessageBox::No:
    // accept();
    this->statusBar()->showMessage("Ok, deletion canceled.", 2000);
    break;
  default:
    break;
  }
  // Refresh the sales table
  this->refreshDb();
  this->updateTable();
  this->updateStats();
}

void stock_manager::deleteSoldItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  QTableWidgetItem *tblItem = this->m_ui->tblSales->selectedItems().first();
  int id = this->m_ui->tblSales->item(tblItem->row(), 0)->text().toInt();
  std::string name =
      this->m_ui->tblSales->item(tblItem->row(), 1)->text().toStdString();
  int ret =
      QMessageBox::warning(this, "Stock Manager",
                           QString("Are you sure you want to delete %1 ?")
                               .arg(QString::fromStdString(name)),
                           QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

  switch (ret) {
  case QMessageBox::Yes:
    // Delete from db
    storage->remove<SoldItem>(id);
    this->statusBar()->showMessage("Item deleted succefully.", 2000);
    break;
  case QMessageBox::No:
    // accept();
    this->statusBar()->showMessage("Ok, deletion canceled.", 2000);
    return;
    break;
  default:
    break;
  }

  // Update sales table
  this->updateSales();
  this->updateSalesStats();
}

void stock_manager::editSelectedSoldItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  long price;
  try {
    QTableWidgetItem *tblItem = this->m_ui->tblSales->selectedItems().first();

    // get sold item id
    QString id = this->m_ui->tblSales->item(tblItem->row(), 0)->text();
    this->ui_dlg_edit_sale.lblId->setText(id);

    auto sold_itm = storage->get_all_pointer<SoldItem>(
        where(c(&SoldItem::id) == id.toInt()));
    auto itm = storage->get_all_pointer<Item>(
        where(c(&Item::itemNo) == sold_itm[0]->itemNo));

    if (sold_itm[0]->sellingPrice != nullptr) {
      price = *(sold_itm[0]->sellingPrice);
    } else {
      // Use the item price
      price = itm[0]->price;
    }

    if (sold_itm[0]->paymentMethod == "Cash") {
      this->ui_dlg_edit_sale.cmbPayment_Method->setCurrentIndex(0);
    } else {
      this->ui_dlg_edit_sale.cmbPayment_Method->setCurrentIndex(1);
    }

    // this->ui_dlg_edit_sale.txtName->setText(QString::fromStdString(itm[0]->name));
    this->ui_dlg_edit_sale.lblId->setText(QString::number(sold_itm[0]->id));
    this->ui_dlg_edit_sale.txtId->setText(
        QString::fromStdString(sold_itm[0]->itemNo));
    this->ui_dlg_edit_sale.spnQuantity->setValue(sold_itm[0]->quantity);
    this->ui_dlg_edit_sale.dateTimeSale->setDateTime(
        QDateTime::fromSecsSinceEpoch(sold_itm[0]->saleDate));
    this->ui_dlg_edit_sale.spnSale_Price->setValue(price);

    // Show the dialog
    this->dlg_edit_sale.show();
  } catch (...) {
    // Just in case
    this->statusBar()->showMessage("Oops, something went wrong", 2000);
  }
}

void stock_manager::editSelectedItem() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  try {
    QTableWidgetItem *tblItem = this->m_ui->tblStock->selectedItems().first();

    // get itemNo in the first column
    QString id = this->m_ui->tblStock->item(tblItem->row(), 0)->text();
    this->ui_dlg_edit.txtId->setText(id);

    auto itm = storage->get_all_pointer<Item>(
        where(c(&Item::itemNo) == id.toStdString()));

    auto stock_item = storage->get_all_pointer<Stock>(
        where(c(&Stock::itemNo) == id.toStdString()));

    this->ui_dlg_edit.txtId->setText(QString::fromStdString(itm[0]->itemNo));
    this->ui_dlg_edit.txtName->setText(QString::fromStdString(itm[0]->name));
    this->ui_dlg_edit.txtCapacity->setText(
        QString::fromStdString(itm[0]->capacity));
    this->ui_dlg_edit.spnQuantity->setValue(stock_item[0]->quantity);
    this->ui_dlg_edit.spnSellingPrice->setValue(itm[0]->price);
    this->ui_dlg_edit.spnBuyingPrice->setValue(itm[0]->buyingPrice);
    this->ui_dlg_edit.spnMinimumSellingPrice->setValue(itm[0]->minimumPrice);
    this->dlg_edit.show();
  } catch (...) {
    // qError("Error cannot edit item");
    this->statusBar()->showMessage("Oops, something went wrong", 2000);
  }
}

// Context menus
void stock_manager::editContext(QPoint pos) {
  QMenu menu(this);
  QList<QTableWidgetItem *> itemList;

  this->stockPoint = pos;

  this->actDelete->setText("Delete");
  this->actEdit->setText("Edit");
  itemList = this->m_ui->tblStock->selectedItems();

  // Add 'edit' to context menu only
  // when there is an item selected
  if (itemList.count() > 0) {
    menu.addAction(this->actDelete);
    menu.addAction(this->actEdit);
    menu.addSeparator();
  }
  menu.addAction(this->m_ui->actHome);
  menu.addAction(this->m_ui->actSales);
  menu.addAction(this->m_ui->actStock);
  menu.addSeparator();
  menu.addAction(this->m_ui->actQuit);
  // Show the context menu
  menu.exec(this->m_ui->tblStock->mapToGlobal(pos));
}

void stock_manager::editSaleContext(QPoint pos) {
  QMenu menu(this);
  QList<QTableWidgetItem *> itemList;

  this->salePoint = pos;

  this->actDelete_Sale->setText("Delete");
  this->actEdit_Sale->setText("Edit");
  itemList = this->m_ui->tblSales->selectedItems();

  // Add 'edit sale' to context menu only
  // when there is an item selected
  if (itemList.count() > 0) {
    menu.addAction(this->actDelete_Sale);
    menu.addAction(this->actEdit_Sale);
    menu.addSeparator();
  }
  menu.addAction(this->m_ui->actHome);
  menu.addAction(this->m_ui->actSales);
  menu.addAction(this->m_ui->actStock);
  menu.addSeparator();
  menu.addAction(this->m_ui->actQuit);
  // Show the context menu
  menu.exec(this->m_ui->tblSales->mapToGlobal(pos));
}

void stock_manager::changePassword() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath()));
  storage->on_open = [](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };

  if (this->ui_dlg_settings.txtOld_Pass->text().isEmpty() ||
      this->ui_dlg_settings.txtConfirm_Pass->text().isEmpty() ||
      this->ui_dlg_settings.txtNew_Pass->text().isEmpty()) {
    QMessageBox::warning(this, "Stock Manager",
                         "All password fields are required\n"
                         "Please enter all the password fields",
                         QMessageBox::Ok);
    return;
  }
  if (this->ui_dlg_settings.txtNew_Pass->text() !=
      this->ui_dlg_settings.txtConfirm_Pass->text()) {
    QMessageBox::warning(this, "Stock Manager",
                         "Password confirmation do not match.\n"
                         "Please enter the correct password",
                         QMessageBox::Ok);
    this->ui_dlg_settings.txtOld_Pass->setText("");
    this->ui_dlg_settings.txtNew_Pass->setText("");
    this->ui_dlg_settings.txtConfirm_Pass->setText("");
    return;
  }

  if (QCryptographicHash::hash(
          this->ui_dlg_settings.txtOld_Pass->text().toUtf8(),
          QCryptographicHash::Sha256)
          .toHex()
          .toStdString() != Settings::getInstance().getUser()->password) {
    QMessageBox::warning(this, "Stock Manager",
                         "Incorrect user password.\n"
                         "Please enter the correct password",
                         QMessageBox::Ok);
    return;
  }

  User *user = Settings::getInstance().getUser();
  user->password = QCryptographicHash::hash(
                       this->ui_dlg_settings.txtNew_Pass->text().toUtf8(),
                       QCryptographicHash::Sha256)
                       .toHex()
                       .toStdString();
  storage->update(*user);
}

void stock_manager::backupDb() {
  std::string backup_file;
  QDir backup_dir = util::getBackupPath();
  std::string db_path = util::getDBPath(DB_FILE);
  backup_file = backup_dir
                    .filePath(QString("%1.db").arg(
                        QDateTime::currentDateTime().toString("yyyyMMddhhmm")))
                    .toStdString();
  QFile::copy(db_path.c_str(), backup_file.c_str());
  this->statusBar()->showMessage(QString("Database backup created at %1")
                                     .arg(QString::fromStdString(backup_file)),
                                 2000);
}

#ifndef QT_NO_CONTEXTMENU
void stock_manager::contextMenuEvent(QContextMenuEvent *event) {
  QMenu menu(this);
  menu.addAction(this->m_ui->actHome);
  menu.addAction(this->m_ui->actSales);
  menu.addAction(this->m_ui->actStock);
  menu.addSeparator();
  menu.addAction(this->m_ui->actQuit);
  menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

stock_manager::~stock_manager() = default;
