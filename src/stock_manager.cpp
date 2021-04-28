/*
 * Copyright (c) 2020 Noah Too
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
#include "utils.h"

#include <iostream>

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>
#include <sqlcipher/sqlite3.h>

#include <QtCore/QDateTime>
#include <QtGui/QKeySequence>
#include <QtGui/QContextMenuEvent>
#include <QtWidgets/QAction>
#include <QtWidgets/QDialog>
#include <QtWidgets/QShortcut>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>

stock_manager::stock_manager(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::stock_manager)
{
    dlg_add = new dlgAdd(this);
    dlg_about = new dlgAbout(this);
    dlg_add_new = new dlgAddNew(this, cart);

    ui_dlg_search.setupUi(&dlg_search);
    ui_dlg_settings.setupUi(&dlg_settings);
    m_ui->setupUi(this);

    this->stockCount = 0;
    m_ui->dateSales->setDate(QDate::currentDate());
    m_ui->dateSales->setMaximumDate(QDate::currentDate());

    QShortcut *cartShortcut = new QShortcut(QKeySequence("Ctrl+1"), this);
    QShortcut *salesShortcut = new QShortcut(QKeySequence("Ctrl+2"), this);
    QShortcut *stockShortcut = new QShortcut(QKeySequence("Ctrl+3"), this);

    connect(m_ui->btnSell_Cart, &QPushButton::pressed, this, &stock_manager::sellItems);
    connect(m_ui->btnClear_Cart, &QPushButton::pressed, this, &stock_manager::clearCart);
    connect(m_ui->actQt_About, &QAction::triggered, this, QApplication::aboutQt);
    connect(m_ui->actQuit, &QAction::triggered, this, &QCoreApplication::quit);
    connect(m_ui->dateSales, &QDateEdit::dateChanged, this, &stock_manager::updateSales);
    connect(m_ui->btnRefreshSales, &QPushButton::pressed, this, 
        [&]() {
            updateSales(
                m_ui->dateSales->date()
            );
            updateSalesStats();
        });
    connect(cartShortcut, &QShortcut::activated, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(0);
        });
    connect(salesShortcut, &QShortcut::activated, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(1);
        });
    connect(stockShortcut, &QShortcut::activated, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(2);
        });
    connect(m_ui->btnAdd_Cart, &QPushButton::pressed, this,
        [&]() {
            dlg_add_new->show();
        });
    connect(
        m_ui->btnAddItem,
        &QPushButton::pressed, this,
        [=]() { dlg_add->show(); });
    connect(
        m_ui->btnRefresh,
        &QPushButton::pressed, this,
        [&]() {
            refreshDb();
            updateTable();
            updateStats();
        });
    connect(
        dlg_add,
        &QDialog::accepted, this,
        [&]() {
            refreshDb();
            updateTable();
            updateStats();
        });
    connect(
        dlg_add_new,
        &QDialog::accepted, this,
        [&]() {
            updateCart();
        });
    connect(
        m_ui->actSettings_2,
        &QAction::triggered, this,
        [=]() { dlg_settings.show(); });
    connect(
        m_ui->actionSearch,
        &QAction::triggered, this,
        [=]() { dlg_search.show(); });
    connect(
        m_ui->actAbout,
        &QAction::triggered, this,
        [=]() { dlg_about->show(); });
    connect(
        m_ui->actHome,
        &QAction::triggered, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(0);
        });
    connect(
        m_ui->actSales,
        &QAction::triggered, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(1);
        });
    connect(
        m_ui->actStock,
        &QAction::triggered, this,
        [&]() {
            m_ui->tabMain->setCurrentIndex(2);
        });

    refreshDb();
    updateTable();
    updateStats();
    updateSales();
    updateSalesStats();
}

void stock_manager::refreshDb()
{
    using namespace sqlite_orm;
    this->setCursor(Qt::BusyCursor);
    items.clear();
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3 *db) {
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    auto allItems = storage->select(
        columns(
            &Item::id, &Item::itemNo, &Item::name,
            &Item::price, &Item::capacity, &Stock::quantity),
        where(c(&Item::itemNo) == &Stock::itemNo and c(&Stock::quantity) > 0),
        order_by(&Item::id));

    for (auto &itm : allItems) {
        items.push_back(
            Items{
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

void stock_manager::updateTable()
{
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
        tblItem3->setText(
            QString::fromStdString(
                util::formatCurrency(
                    util::formatNumber(itm.price))));
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

void stock_manager::updateStats()
{
    json data = getStatsData();
    QString stats_template = "<html><head/><body>";

    if (data.contains("stock"))
        stats_template.push_back(
            QString::fromStdString(
                inja::render("<p>Stock: {{ stock.count }} of {{ stock.items }} items</p>", data)));

    if (data.contains("sales"))
        stats_template.push_back(
            QString::fromStdString(
                inja::render("<p>Sales Today: {{ sales.count }} for {{ sales.price }}</p>", data)));

    if (data.contains("items") || data["items"].size() > 0)
        stats_template.push_back(
            QString::fromStdString(
                inja::render(R"(<p><span style=" font-weight:600;">Items Out of Stock:</span></p><p>
## for item in items
{{ loop.index1 }}: {{ item }}<br/>
## endfor
</p>)",
                             data)));
    stats_template.push_back("</body></html>");

    m_ui->lblStats->setText(stats_template);
}

json stock_manager::getStatsData()
{
    using namespace sqlite_orm;
    json j;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3 *db) {
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    j["stock"]["items"] = storage->count<Stock>();
    j["stock"]["count"] = this->stockCount;

    QDateTime date_time = QDateTime::currentDateTime();
    date_time.setTime(QTime::fromString("00:00:00", "HH:mm:ss"));

    long int timestamp = date_time.toSecsSinceEpoch();

    auto sales = storage->select(
        columns(&Item::price, &SoldItem::quantity),
        where(c(&Item::itemNo) == &SoldItem::itemNo and c(&SoldItem::saleDate) >= timestamp));

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
        j["items"].push_back(std::get<0>(itm));
    }
    return j;
}

void stock_manager::updateCart()
{
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
        tblItem3->setText(
            QString::fromStdString(
                util::formatCurrency(
                    util::formatNumber(itm.price))));
        m_ui->tblCart->setItem(count, 2, tblItem3);

        QTableWidgetItem *tblItem4 = new QTableWidgetItem();
        tblItem4->setText(QString::number(itm.quantity));
        m_ui->tblCart->setItem(count, 3, tblItem4);

        QTableWidgetItem *tblItem5 = new QTableWidgetItem();
        tblItem5->setText(
            QString::fromStdString(
                util::formatCurrency(
                    util::formatNumber(itm.totalPrice))));
        totalPrice += itm.totalPrice;
        m_ui->tblCart->setItem(count, 4, tblItem5);

        count++;
    }
    j["count"] = count;
    j["total"] = util::formatCurrency(util::formatNumber(totalPrice));
    m_ui->lblItem_Count->setText(
        QString::fromStdString(
            inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style="font-size:12pt;">Items On Cart: {{ count }}</span>
        </p>
    </body>
</html>)",
                j)));
    m_ui->lblTotal->setText(
        QString::fromStdString(
            inja::render(R"(
<html>
    <head/>
    <body>
    <p><span style="font-size:16pt;">Total: {{ total }}</span></p>
    </body>
</html>)",
                j)));
}

void stock_manager::clearCart()
{
    this->cart.clear();
    this->updateCart();
}

void stock_manager::sellItems()
{
    using namespace sqlite_orm;
    // Don't even try when cart is empty
    if (this->cart.empty()) {
        QMessageBox msgBox;
        msgBox.setText("Cart Empty!");
        msgBox.setInformativeText("Cannot sell an empty cart");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        return;
    }
    this->setCursor(Qt::BusyCursor);
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3 *db) {
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    long int date = QDateTime::currentSecsSinceEpoch();
    std::string payment_method = this->m_ui->cmbPayment_Method->currentText().toStdString();

    try {
        auto guard = storage->transaction_guard();
        for (auto &itm : this->cart) {
            storage->insert(SoldItem{
                itm.itemNo,
                itm.quantity,
                payment_method,
                date});
            auto items = storage->get_all_pointer<Stock>(
                where(c(&Stock::itemNo) == itm.itemNo));

            storage->update_all(
                set(c(&Stock::quantity) = items[0]->quantity - itm.quantity),
                where(c(&Stock::itemNo) == itm.itemNo));
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
    this->statusBar()->showMessage("Items sold", 2000);
}

void stock_manager::updateSales(QDate ch_date)
{
    using namespace sqlite_orm;
    long start, end;
    json j;
    QDateTime date;
    this->setCursor(Qt::BusyCursor);
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3 *db) {
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    date.setDate(ch_date);
    date.setTime(QTime::fromString("00:00:00", "HH:mm:ss"));
    start = date.toSecsSinceEpoch();
    date.setTime(QTime::fromString("23:59:59", "HH:mm:ss"));
    end = date.toSecsSinceEpoch();

    auto items = storage->select(
        columns(&Item::itemNo, &Item::name, &SoldItem::quantity,
            &Item::price, &SoldItem::paymentMethod, &SoldItem::saleDate),
        where(c(&Item::itemNo) == &SoldItem::itemNo and
            c(&SoldItem::saleDate) >= start and c(&SoldItem::saleDate) <= end));

    int count = 0;
    int quantity = 0;
    long salesMade = 0;
    this->m_ui->tblSales->clearContents();
    this->m_ui->tblSales->setRowCount(items.size());

    for (auto &itm : items) {
        // Item::itemNo
        QTableWidgetItem *tblItem0 = new QTableWidgetItem();
        tblItem0->setText(QString::fromStdString(std::get<0>(itm)));
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
            util::formatCurrency(util::formatNumber(std::get<3>(itm)))));
        m_ui->tblSales->setItem(count, 3, tblItem3);

        // Total price
        QTableWidgetItem *tblItem4 = new QTableWidgetItem();
        tblItem4->setText(QString::fromStdString(
            util::formatCurrency(
                util::formatNumber(std::get<3>(itm) * std::get<2>(itm)))));
        m_ui->tblSales->setItem(count, 4, tblItem4);

        // SoldItem::paymentMethod
        QTableWidgetItem *tblItem5 = new QTableWidgetItem();
        tblItem5->setText(QString::fromStdString(std::get<4>(itm)));
        m_ui->tblSales->setItem(count, 5, tblItem5);

        // SoldItem::saleDate
        QDateTime date_time = QDateTime::fromSecsSinceEpoch(std::get<5>(itm));
        QTableWidgetItem *tblItem6 = new QTableWidgetItem();
        tblItem6->setText(date_time.toString("dd-MM-yyyy"));
        m_ui->tblSales->setItem(count, 6, tblItem6);

        salesMade += std::get<3>(itm) * std::get<2>(itm);
        count++;
    }
    j["count"] = quantity;
    j["sales"] = util::formatCurrency(util::formatNumber(salesMade));
    j["date"] = date.toString("ddd dd MMMM yyyy").toStdString();
    this->m_ui->lblSalesStats->setText(
        QString::fromStdString(
            inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style="font-size:12pt;">Sales Made on </span>
            <span style="font-size:12pt; font-weight:600;">{{ date }}</span>
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
    this->unsetCursor();
}

void stock_manager::updateSalesStats()
{
    using namespace sqlite_orm;
    json j, jDate;
    QDate dt;
    QDateTime date;
    long wStart, mStart, end;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3 *db) {
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    date = QDateTime::currentDateTime();
    end = date.toSecsSinceEpoch();
    dt = date.date();
    jDate["month"] = dt.month();
    jDate["year"] = dt.year();
    jDate["date"] = dt.day() - (dt.dayOfWeek() - 1);
    dt = QDate::fromString(
        QString::fromStdString(
            inja::render(
                "{{ date }}-{{ month }}-{{ year }}",
                jDate
            )
        ),
        "d-M-yyyy"
    );
    date = dt.startOfDay();
    wStart = date.toSecsSinceEpoch();
    dt = QDate::fromString(
        QString::fromStdString(
            inja::render(
                "1-{{ month }}-{{ year }}",
                jDate
            )
        ),
        "d-M-yyyy"
    );
    date = dt.startOfDay();
    mStart = date.toSecsSinceEpoch();

    auto wItems = storage->select(
        columns(&SoldItem::quantity, &Item::price),
        where(c(&Item::itemNo) == &SoldItem::itemNo and
            c(&SoldItem::saleDate) >= wStart and c(&SoldItem::saleDate) <= end));
    int w_count = 0;
    int w_sales = 0;
    for (auto &itm: wItems) {
        w_count += std::get<0>(itm);
        w_sales += std::get<1>(itm) * std::get<0>(itm);
    }
    j["w_count"] = w_count;
    j["w_sales"] = util::formatCurrency(util::formatNumber(w_sales));

    auto mItems = storage->select(
        columns(&SoldItem::quantity, &Item::price),
        where(c(&Item::itemNo) == &SoldItem::itemNo and
            c(&SoldItem::saleDate) >= mStart and c(&SoldItem::saleDate) <= end));
    int m_count = 0;
    int m_sales = 0;
    for (auto &itm: mItems) {
        m_count += std::get<0>(itm);
        m_sales += std::get<1>(itm) * std::get<0>(itm);
    }
    j["m_count"] = m_count;
    j["m_sales"] = util::formatCurrency(util::formatNumber(m_sales));

    m_ui->lblSalesStats_2->setText(
        QString::fromStdString(
            inja::render(R"(
<html>
    <head/>
    <body>
        <p>
            <span style=" font-weight:600;">Sales this week:</span><br/>
            {{ w_count }} items for <span style=" font-weight:600;">{{ w_sales }}</span>
        </p>
        <p>
            <span style=" font-weight:600;">Sales this Month:</span><br/>
            {{ m_count }} items for <span style=" font-weight:600;">{{ m_sales }}</span>
        </p>
    </body>
</html>)", j)));
}

#ifndef QT_NO_CONTEXTMENU
void stock_manager::contextMenuEvent(QContextMenuEvent *event)
{
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
