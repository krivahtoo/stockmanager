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
#include "add_new_sell.h"
#include "account.h"
#include "database.h"
#include "structs.h"
#include "ui/ui_edit_item.h"
#include "ui/ui_edit_sale.h"
#include "ui/ui_search.h"
#include "ui/ui_settings.h"
#include "ui/ui_stock_manager.h"

#include <nlohmann/json.hpp>

#include <QtCore/QPoint>
#include <QtWidgets>

QT_BEGIN_NAMESPACE;
class QDialog;
class QMainWindow;
QT_END_NAMESPACE;

using json = nlohmann::json;

class stock_manager : public QMainWindow {
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
  QPoint salePoint;
  QPoint stockPoint;
  QAction *actEdit;
  QAction *actEdit_Sale;
  QAction *actDelete;
  QAction *actDelete_Sale;
  QDialog dlg_settings;
  QDialog dlg_search;
  QDialog dlg_edit;
  QDialog dlg_edit_sale;
  Ui::dlgSearch ui_dlg_search;
  Ui::dlgEdit ui_dlg_edit;
  Ui::dlgEdit_Sale ui_dlg_edit_sale;
  Ui::dlgSettings ui_dlg_settings;
  std::vector<Items> items;
  std::vector<CartItem> cart;
  int stockCount;
  bool timerActive;
  long lastChange;
  json getStatsData();
  void refreshDb();
  void updateTable();
  void updateStats();
  void updateCart();
  void sellItems();
  void updateSales();
  void updateSalesStats();
  void updateItem();
  void updateSoldItem();
  void deleteSoldItem();
  void deleteItem();
  void editSelectedSoldItem();
  void editSelectedItem();
  void editContext(QPoint pos);
  void editSaleContext(QPoint pos);
  void backupDb();
  void changePassword();
};

#endif // STOCK_MANAGER_H
