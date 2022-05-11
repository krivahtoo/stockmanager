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

#include "register.h"
#include "database.h"
#include "settings.h"
#include "utils.h"

#include <sqlcipher/sqlite3.h>

#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>

dlgRegister::dlgRegister(QMainWindow *parent, bool isGenesis)
    : QDialog(parent), ui(new Ui::dlgRegister), isGenesis(isGenesis) {
  ui->setupUi(this);
  ui->lblInfo->setText("");
  if (isGenesis) {
    ui->cmbRole->setEnabled(false);
    ui->cmbRole->addItem("Genesis");
    ui->cmbRole->setCurrentIndex(2);
    ui->lblInfo->setText("Registering a genesis account...");
  }
  connect(ui->btnRegister, &QPushButton::pressed, this, &dlgRegister::reg);
}

void dlgRegister::reg() {
  using namespace sqlite_orm;
  storage = std::make_unique<Storage>(initStorage(util::getDBPath()));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
  };

  // Empty fields are unacceptable
  if (ui->txtName->text().trimmed().isEmpty() ||
      ui->txtUsername->text().trimmed().isEmpty() ||
      ui->txtPassword->text().trimmed().isEmpty() ||
      ui->txtPasswordConfirm->text().trimmed().isEmpty() ||
      ui->cmbRole->currentText().trimmed().isEmpty()) {
    QMessageBox::warning(this, "Error", "Please fill in all fields.");
    return;
  }

  // Password and password confirmation must match
  // TODO: Add password strength check
  if (ui->txtPassword->text() != ui->txtPasswordConfirm->text()) {
    QMessageBox::warning(this, "Error", "Passwords do not match.");
    ui->txtPassword->setText("");
    ui->txtPasswordConfirm->setText("");
    return;
  }

  // Username must be unique
  auto users = storage->get_all<User>();
  for (auto &user : users) {
    if (user.username == ui->txtUsername->text().toStdString()) {
      QMessageBox::warning(this, "Error", "Username is already taken.");
      ui->txtUsername->setText("");
      return;
    }
  }

  // Register user
  User user;
  user.name = ui->txtName->text().trimmed().toStdString();
  user.username = ui->txtUsername->text().trimmed().toStdString();
  user.password = Settings::hash(ui->txtPassword->text().toStdString());
  user.role = ui->cmbRole->currentText().trimmed().toStdString();
  int id = storage->insert(user);

  Settings::user_id = id;

  // Close dialog
  this->accept();
}

dlgRegister::~dlgRegister() = default;
