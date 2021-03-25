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

#include "add_new.h"
#include "database.h"

#include <QMessageBox>

dlgAdd::dlgAdd(QMainWindow *parent):
    QDialog(parent),
    ui(new Ui::dlgAdd)
{
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::pressed, this, &dlgAdd::add);
}

void dlgAdd::add() {
    storage = std::make_unique<Storage>(initStorage(DB_FILE));
    name = ui->txtName->text().toStdString();
    itemNo = ui->txtId->text().toStdString();
    price = ui->spbPrice->cleanText().toLong();
    quantity = ui->spbQuantity->cleanText().toInt();
    Item item{-1, itemNo, name, price};
    auto insertId = storage->insert(item);
    storage->insert(Stock{itemNo, quantity});

    QMessageBox msgBox;
    msgBox.setText("Item added to stock.");
    msgBox.setInformativeText("Do you want to add more items?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int result = msgBox.exec();

    switch (result) {
        case QMessageBox::Ok:
            clearData();
            return;
            break;
        case QMessageBox::Cancel:
            accept();
            break;
        default:
            break;
    }
}

void dlgAdd::clearData() {
    ui->txtId->clear();
    ui->txtName->clear();
    ui->spbPrice->clear();
    ui->spbQuantity->clear();
}

dlgAdd::~dlgAdd() = default;
