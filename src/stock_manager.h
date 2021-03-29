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

#ifndef STOCK_MANAGER_H
#define STOCK_MANAGER_H

#include "about.h"
#include "add_new.h"
#include "sell_items.h"
#include "database.h"
#include "ui_stock_manager.h"
#include "ui_settings.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QDialog>

struct Items
{
    int id;
    std::string itemNo; // This can be WR2536 ;-
    std::string name;
    long price;
    int quantity;
    std::string capacity;
};

class stock_manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit stock_manager(QWidget *parent = nullptr);
    ~stock_manager() override;

    void show_AddItem();
    void show_SellItems();
    void show_About();
    void refreshDb();
    void updateTable();

private:
    QScopedPointer<Ui::stock_manager> m_ui;
    dlgAdd *dlg_add;
    dlgSell *dlg_sell;
    dlgAbout *dlg_about;
    QDialog dlg_settings;
    Ui::dlgSettings ui_dlg_settings;
    std::vector<Items> items;
};

#endif // STOCK_MANAGER_H
