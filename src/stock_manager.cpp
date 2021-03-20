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

stock_manager::~stock_manager() = default;
