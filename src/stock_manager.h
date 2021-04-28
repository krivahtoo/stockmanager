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
#include "structs.h"
#include "add_new.h"
#include "database.h"
#include "ui_search.h"
#include "ui_stock_manager.h"
#include "ui_settings.h"
#include "add_new_sell.h"

#include <nlohmann/json.hpp>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QDialog>

using json = nlohmann::json;

class stock_manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit stock_manager(QWidget *parent = nullptr);
    ~stock_manager() override;

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    QScopedPointer<Ui::stock_manager> m_ui;
    dlgAdd *dlg_add;
    dlgAbout *dlg_about;
    dlgAddNew *dlg_add_new;
    QDialog dlg_settings;
    QDialog dlg_search;
    Ui::dlgSearch ui_dlg_search;
    Ui::dlgSettings ui_dlg_settings;
    std::vector<Items> items;
    std::vector<CartItem> cart;
    int stockCount;
    json getStatsData();
    void refreshDb();
    void updateTable();
    void updateStats();
    void updateCart();
    void sellItems();
    void updateSales(QDate ch_date = QDate::currentDate());
    void updateSalesStats();
};

#endif // STOCK_MANAGER_H
