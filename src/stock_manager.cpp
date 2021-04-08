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
#include "utils.h"

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

#include <QtCore/QDateTime>
#include <QtWidgets/QPushButton>

stock_manager::stock_manager(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::stock_manager)
{
    dlg_add = new dlgAdd(this);
    dlg_about = new dlgAbout(this);
    dlg_add_new = new dlgAddNew(this, cart);

    ui_dlg_settings.setupUi(&dlg_settings);
    m_ui->setupUi(this);

    this->stockCount = 0;

    connect(m_ui->btnAdd_Cart, &QPushButton::pressed, this, &stock_manager::show_AddCart);
    connect(m_ui->actQt_About, &QAction::triggered, this, QApplication::aboutQt);
    connect(m_ui->actQuit, &QAction::triggered, this, &QCoreApplication::quit);
    connect(
        m_ui->btnAddItem,
        &QPushButton::pressed, this,
        [=](){ dlg_add->show(); }
    );
    connect(
        m_ui->btnSellItem,
        &QPushButton::pressed, this,
        [&](){
            m_ui->tabMain->setCurrentIndex(0);
        }
    );
    connect(
        m_ui->btnRefresh,
        &QPushButton::pressed, this,
        [&](){
            refreshDb();
            updateTable();
            updateStats();
        }
    );
    connect(
        dlg_add,
        &QDialog::accepted, this,
        [&](){
            refreshDb();
            updateTable();
            updateStats();
        }
    );
    connect(
        dlg_add_new,
        &QDialog::accepted, this,
        [&](){
            updateCart();
        }
    );
    connect(
        m_ui->actSettings,
        &QAction::triggered, this,
        [=](){ dlg_settings.show(); }
    );
    connect(
        m_ui->actAbout,
        &QAction::triggered, this,
        [=](){ dlg_about->show(); }
    );
    connect(
        m_ui->actHome,
        &QAction::triggered, this,
        [&](){
            m_ui->tabMain->setCurrentIndex(0);
        }
    );
    connect(
        m_ui->actSales,
        &QAction::triggered, this,
        [&](){
            m_ui->tabMain->setCurrentIndex(1);
        }
    );
    connect(
        m_ui->actStock,
        &QAction::triggered, this,
        [&](){
            m_ui->tabMain->setCurrentIndex(2);
        }
    );

    refreshDb();
    updateTable();
    updateStats();
}

void stock_manager::show_AddCart()
{
    dlg_add_new->show();
}

void stock_manager::refreshDb()
{
    using namespace sqlite_orm;
    items.clear();
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    auto allItems = storage->select(
        columns(
            &Item::id, &Item::itemNo, &Item::name,
            &Item::price, &Item::capacity, &Stock::quantity
        ),
        where(c(&Item::itemNo) == &Stock::itemNo),
        order_by(&Item::id), limit(20, offset(0))
    );

    for (auto &itm: allItems) {
        items.push_back(
            Items{
                std::get<0>(itm), // id
                std::get<1>(itm), // itemNo
                std::get<2>(itm), // Name
                std::get<3>(itm), // Price
                std::get<4>(itm), // capacity
                std::get<5>(itm) // quantity
            }
        );
    }
}

void stock_manager::updateTable()
{
    int count = 0;
    m_ui->tblStock->clearContents();
    m_ui->tblStock->setRowCount(items.size());
    for (const auto& itm: items) {
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
                    util::formatNumber(itm.price)
                )
            )
        );
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
                inja::render("<p>Stock: {{ stock.count }} of {{ stock.items }} items</p>", data)
            )
        );

    if (data.contains("sales"))
        stats_template.push_back(
            QString::fromStdString(
                inja::render("<p>Sales Today: {{ sales.count }} for {{ sales.price }}</p>", data)
            )
        );

    if (data.contains("items") || data["items"].size() > 0)
        stats_template.push_back(
            QString::fromStdString(
                inja::render(R"(<p><span style=" font-weight:600;">Items Out of Stock:</span></p>: <p>
## for item in items
{{ loop.index1 }}: {{ item }}<br/>
## endfor
</p>)", data)
            )
        );
    stats_template.push_back("</body></html>");

    m_ui->lblStats->setText(stats_template);
}

json stock_manager::getStatsData()
{
    using namespace sqlite_orm;
    json j;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    j["stock"]["items"] = storage->count<Stock>();
    j["stock"]["count"] = this->stockCount;

    QDateTime date_time = QDateTime::currentDateTime();
    date_time.setTime(QTime::fromString("00:00:00", "HH:mm:ss"));

    long int timestamp = date_time.toSecsSinceEpoch();

    auto sales = storage->select(
        columns(&Item::price, &SoldItem::quantity),
        where(c(&Item::itemNo) == &Stock::itemNo and c(&SoldItem::saleDate) >= timestamp)
    );

    int count = 0;
    long price = 0;

    for (auto &sale: sales) {
        price += std::get<0>(sale);
        count += std::get<1>(sale);
    }

    j["sales"]["count"] = count;
    j["sales"]["price"] = util::formatCurrency(util::formatNumber(price));

    auto items = storage->select(
        columns(&Item::name, &Stock::quantity),
        where(c(&Item::itemNo) == &Stock::itemNo and c(&Stock::quantity) < 1)
    );

    for (auto &itm: items) {
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
    for(auto &itm: this->cart) {
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
                    util::formatNumber(itm.price)
                )
            )
        );
        m_ui->tblCart->setItem(count, 2, tblItem3);

        QTableWidgetItem *tblItem4 = new QTableWidgetItem();
        tblItem4->setText(QString::number(itm.quantity));
        m_ui->tblCart->setItem(count, 3, tblItem4);

        QTableWidgetItem *tblItem5 = new QTableWidgetItem();
        tblItem5->setText(
            QString::fromStdString(
                util::formatCurrency(
                    util::formatNumber(itm.totalPrice)
                )
            )
        );
        totalPrice += itm.totalPrice;
        m_ui->tblCart->setItem(count, 4, tblItem5);

        count++;
    }
    j["count"] = count;
    j["total"] = util::formatCurrency(util::formatNumber(totalPrice));
    m_ui->lblItem_Count->setText(
        QString::fromStdString(
            inja::render(
                "<html><head/><body><p><span style=\" font-size:12pt;\">Items On Cart: {{ count }}</span></p></body></html>",
                j
            )
        )
    );
    m_ui->lblTotal->setText(
        QString::fromStdString(
            inja::render(
                "<html><head/><body><p><span style=\" font-size:16pt;\">Total: {{ total }}</span></p></body></html>",
                j
            )
        )
    );
}

stock_manager::~stock_manager() = default;
