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

#include "add_new_sell.h"
#include "database.h"
#include "structs.h"
#include "utils.h"

#include <QtCore/QString>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

dlgAddNew::dlgAddNew(QWidget *parent, std::vector<CartItem> &cart_items):
    QDialog(parent),
    ui(new Ui::dlgAddNew),
    cart(cart_items)
{
    ui->setupUi(this);

    connect(ui->btnAdd, &QPushButton::pressed, this, &dlgAddNew::addToCart);
    connect(ui->txtId, &QLineEdit::textChanged, this, &dlgAddNew::updateItem);
}

void dlgAddNew::addToCart()
{
    this->item.quantity = this->ui->spbQuantity->text().toInt();
    this->item.totalPrice = item.price * item.quantity;
    this->cart.push_back(item);
    accept();
}

void dlgAddNew::updateItem(QString id)
{
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    auto item_count = storage->count<Item>(
        where(c(&Item::itemNo) == id.toStdString())
    );
    if (item_count < 1) {
        this->ui->txtName->setText("Item you entered does not exists..");
        this->ui->btnAdd->setEnabled(false);
        this->ui->spbQuantity->setEnabled(false);
        return;
    } else {
        this->ui->spbQuantity->setEnabled(true);
        this->ui->btnAdd->setEnabled(true);

        auto stock = storage->get_all_pointer<Stock>(
            where(c(&Stock::itemNo) == id.toStdString())
        );
        this->ui->spbQuantity->setMaximum(stock[0]->quantity);
    
        auto itm = storage->get_all_pointer<Item>(
            where(c(&Item::itemNo) == id.toStdString())
        );
        this->ui->txtName->setText(QString::fromStdString(itm[0]->name));
        this->item.itemNo = itm[0]->itemNo;
        this->item.name = itm[0]->name;
        this->item.price = itm[0]->price;
    }
}

dlgAddNew::~dlgAddNew() = default;
