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
#include "settings.h"
#include "structs.h"
#include "utils.h"

#include <sqlcipher/sqlite3.h>

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
    connect(ui->txtSearch, &QLineEdit::textChanged, this, &dlgAddNew::updateSearch);

    ui->btnAdd->setEnabled(false);
    ui->spbQuantity->setEnabled(false);
    ui->spbQuantity->setMinimum(1);

    ui->txtSearch->setPlaceholderText("Search...");
    ui->txtId->setPlaceholderText("Enter item id...");
}

void dlgAddNew::addToCart()
{
    this->item.quantity = this->ui->spbQuantity->text().toInt();
    this->item.totalPrice = item.price * item.quantity;
    this->cart.push_back(item);
    this->ui->txtId->clear();
    this->ui->spbQuantity->setValue(1);
    accept();
}

void dlgAddNew::updateItem(QString id)
{
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3* db){
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    auto item_count = storage->count<Item>(
        where(c(&Item::itemNo) == id.toStdString())
    );
    if (item_count < 1) {
        this->ui->txtName->setText("Item you entered does not exists..");
        return;
    } else {
        auto stock = storage->get_all_pointer<Stock>(
            where(c(&Stock::itemNo) == id.toStdString())
        );

        if (stock[0]->quantity < 1) {
            this->ui->txtName->setText("Item you entered is out of stock..");
            return;
        }
        this->ui->spbQuantity->setEnabled(true);
        this->ui->btnAdd->setEnabled(true);
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

void dlgAddNew::updateSearch(QString text)
{
    using namespace sqlite_orm;
    storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
    storage->on_open = [&](sqlite3* db){
        sqlite3_key(db, Settings::db_key.c_str(), Settings::db_key.size());
    };
    this->ui->lstSearch->clear();
    if (text.isEmpty()) return;
    text.prepend("%");
    text.append("%");
    auto items = storage->get_all_pointer<Item>(where(like(&Item::name, text.toStdString())));
    // cout << "items = " << items.size() << endl;
    for(auto &item : items) {
        QString txt = QString::fromStdString(item->itemNo);
        txt.append(" | ");
        txt.append(QString::fromStdString(item->name));
        txt.append(" | ");
        txt.append(QString::fromStdString(
            util::formatCurrency(
                util::formatNumber(item->price)
            )
        ));
        new QListWidgetItem(txt, this->ui->lstSearch);
    }
}

dlgAddNew::~dlgAddNew() = default;
