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

#include "utils.h"
#include "add_new.h"
#include "database.h"

#include <QtCore/QDateTime>
#include <QtCore/QVariant>
#include <QtWidgets/QMessageBox>

dlgAdd::dlgAdd(QMainWindow *parent):
    QDialog(parent),
    ui(new Ui::dlgAdd)
{
    newItem = true;
    ui->setupUi(this);

    connect(ui->btnSave, &QPushButton::pressed, this, &dlgAdd::add);
    connect(ui->txtId, &QLineEdit::textChanged, this, &dlgAdd::updateItem);

    ui->txtCapacity->setPlaceholderText("e.g. 500g, 100ml");
    ui->txtId->setPlaceholderText("Enter item no/ serial no...");
    ui->txtName->setPlaceholderText("Enter the item name...");
}

void dlgAdd::add()
{
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath()));
    if (newItem) {
        name = ui->txtName->text().toStdString();
        itemNo = ui->txtId->text().toStdString();
        price = ui->spnPrice->cleanText().toLong();
        buyingPrice = ui->spnBuyingPrice->cleanText().toLong();
        capacity = ui->txtCapacity->text().toStdString();
        quantity = ui->spnQuantity->cleanText().toInt();
        
        storage->insert(Item {-1,
            itemNo, name, price,
            buyingPrice, capacity,
            QDateTime::currentSecsSinceEpoch()
        });
        storage->insert(Stock{itemNo, quantity});
    } else {
        auto itemQuantity = storage->select(
            &Stock::quantity,
            where(c(&Stock::itemNo) == itemNo)
        );
        int item_quantity = *(itemQuantity.data());
        item_quantity += quantity;
        storage->update_all(
            set(c(&Stock::quantity) = item_quantity),
            where(c(&Stock::itemNo) == itemNo)
        );
    }

    QMessageBox msgBox;
    msgBox.setText("Item added to stock.");
    msgBox.setInformativeText("Do you want to add more items?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int result = msgBox.exec();

    clearData();

    switch (result) {
        case QMessageBox::Ok:
            return;
            break;
        case QMessageBox::Cancel:
            accept();
            break;
        default:
            break;
    }
}

void dlgAdd::clearData()
{
    ui->txtId->clear();
    ui->txtName->clear();
    ui->spnPrice->setValue(0);
    ui->txtCapacity->clear();
    ui->spnBuyingPrice->setValue(0);
    ui->spnQuantity->setValue(1);
}

// new QListWidgetItem(tr("Oak"), this->m_ui->ls);

void dlgAdd::updateItem(QString id)
{
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    auto item_count = storage->count<Item>(
        where(c(&Item::itemNo) == id.toStdString())
    );
    if (item_count < 1) {
        this->newItem = true;
        return;
    } else {
        this->newItem = false;
        auto stock = storage->get_all_pointer<Item>(
            where(c(&Item::itemNo) == id.toStdString())
        );

        this->ui->txtName->setEnabled(false);
        this->ui->txtCapacity->setEnabled(false);
    
        auto itm = storage->get_all_pointer<Item>(
            where(c(&Item::itemNo) == id.toStdString())
        );
        this->ui->txtName->setText(QString::fromStdString(itm[0]->name));
        this->ui->txtCapacity->setText(QString::fromStdString(itm[0]->capacity));
        this->ui->spnPrice->setValue(itm[0]->price);
        this->ui->spnBuyingPrice->setValue(itm[0]->buyingPrice);
    }
}

dlgAdd::~dlgAdd() = default;
