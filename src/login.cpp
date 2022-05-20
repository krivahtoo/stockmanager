/*
 * Copyright (c) 2022 Noah Too
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

#include "login.h"
#include "database.h"
#include "register.h"
#include "settings.h"
#include "structs.h"
#include "utils.h"

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QtCore/QCryptographicHash>

dlgLogin::dlgLogin(QMainWindow *parent)
    : QDialog(parent), ui(new Ui::dlgLogin) {
  ui->setupUi(this);
  dlg_register = new dlgRegister(parent, true);

  connect(ui->btnLogin, &QPushButton::pressed, this, &dlgLogin::login);

  ui->txtUsername->setPlaceholderText("Enter username");
  ui->txtPassword->setPlaceholderText("Enter password");
}

void dlgLogin::login() {
  if (ui->txtUsername->text().isEmpty() || ui->txtPassword->text().isEmpty()) {
    QMessageBox::warning(this, "Login",
                         "Please enter a username and password.");
    return;
  }
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath()));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };

  std::string hash = QCryptographicHash::hash(ui->txtPassword->text().toUtf8(),
                                              QCryptographicHash::Sha256)
                         .toHex()
                         .toStdString();
  std::string username = ui->txtUsername->text().trimmed().toStdString();
  auto user = storage->get_all_pointer<User>(
      where(c(&User::username) == username && c(&User::password) == hash));

  if (user.empty()) {
    QMessageBox::warning(this, "Login", "Username or password is incorrect.");
    ui->txtPassword->clear();
    return;
  }

  Settings::getInstance().setUser(user[0].release());

  accept();
}

int dlgLogin::getUserCount() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath()));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  return storage->count<User>();
}

void dlgLogin::showEvent(QShowEvent *event) {
  if (this->getUserCount() <= 0) {
    this->setDisabled(true);
    dlg_register->setModal(true);
    dlg_register->show();
    connect(dlg_register, &QDialog::rejected, this, &dlgLogin::reject);
    connect(dlg_register, &QDialog::accepted, this, [&]() {
      QMessageBox::information(this, "Registration",
                               "Registration successful!");
      this->setEnabled(true);
    });
  }
}

dlgLogin::~dlgLogin() = default;
