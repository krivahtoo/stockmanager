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

#include "database.h"
#include "login.h"
#include "settings.h"
#include "stock_manager.h"
#include "version.h"

#include <QtWidgets/QApplication>

#ifndef DB_KEY
#define DB_KEY "0b09389dad0aad0216dc94ff2881f8098dce2f67ad531b0dd0f2071cc2e2fcdb"
#endif

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.setApplicationDisplayName("Shop Manager");
  app.setApplicationName("StockManager");
  app.setApplicationVersion(VERSION);
  app.setOrganizationName("KrivArt");
  // TODO: Use key from hash
  Settings::getInstance().setDBKey(DB_KEY);
  Settings::getInstance().saveSettings();
  updateDb();
  stock_manager w;
  QDialog *dlg_login = new dlgLogin(&w);
  dlg_login->show();
  w.connect(dlg_login, &QDialog::rejected, &w, []() { exit(1); });
  w.connect(dlg_login, &QDialog::accepted, &w, [&]() {
    w.setWindowState(Qt::WindowMaximized);
    w.show();
  });

  return app.exec();
}
