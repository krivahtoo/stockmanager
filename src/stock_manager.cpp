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

#include <QtWidgets/QPushButton>

stock_manager::stock_manager(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::stock_manager)
{
    dlg_add = new dlgAdd(this);
    dlg_sell = new dlgSell(this);
    dlg_about = new dlgAbout(this);
    m_ui->setupUi(this);

    connect(m_ui->actQt_About, &QAction::triggered, this, QApplication::aboutQt);
    connect(m_ui->actQuit, &QAction::triggered, this, &QCoreApplication::quit);
    connect(m_ui->btnAddItem, &QPushButton::pressed, this, &stock_manager::show_AddItem);
    connect(m_ui->btnSellItem, &QPushButton::pressed, this, &stock_manager::show_SellItems);
    connect(m_ui->actAbout, &QAction::triggered, this, &stock_manager::show_About);

    // m_ui->tblStock
    refreshDb();
    updateTable();
}

void stock_manager::show_AddItem()
{
    dlg_add->show();
}

void stock_manager::show_SellItems()
{
    dlg_sell->show();
}

void stock_manager::show_About()
{
    dlg_about->show();
}

void stock_manager::refreshDb() {
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(getDBPath()));
    auto allItems = storage->select(
        columns(&Item::id, &Item::itemNo, &Item::name, &Item::price, &Stock::quantity),
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
                std::get<4>(itm) // quantity
            }
        );
    }
}

void stock_manager::updateTable() {
    int count = 0;
    m_ui->tblStock->setRowCount(items.size());
    for (const auto& itm: items) {
        QTableWidgetItem *tblItem1 = new QTableWidgetItem();
        tblItem1->setText(QString::fromStdString(itm.itemNo));
        m_ui->tblStock->setItem(count, 0, tblItem1);

        QTableWidgetItem *tblItem2 = new QTableWidgetItem();
        tblItem2->setText(QString::fromStdString(itm.name));
        m_ui->tblStock->setItem(count, 1, tblItem2);

        QTableWidgetItem *tblItem3 = new QTableWidgetItem();
        tblItem3->setText(QString::number(itm.price));
        m_ui->tblStock->setItem(count, 2, tblItem3);

        QTableWidgetItem *tblItem4 = new QTableWidgetItem();
        tblItem4->setText(QString::number(itm.quantity));
        m_ui->tblStock->setItem(count, 3, tblItem4);

        // QTableWidgetItem *tblItem5 = new QTableWidgetItem();
        // tblItem5->setText();
        // m_ui->tblStock->setItem(count, 4, tblItem5);

        count++;
    }
}

stock_manager::~stock_manager() = default;
