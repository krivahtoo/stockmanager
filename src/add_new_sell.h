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

#ifndef ADD_NEW_SELL_H
#define ADD_NEW_SELL_H

#include "ui/ui_add_new_sell.h"
#include "database.h"

#include <QtCore/QString>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>

class dlgAddNew: public QDialog
{
    Q_OBJECT

public:
    explicit dlgAddNew(QWidget *parent, std::vector<CartItem> &cart);
    ~dlgAddNew() override;

private:
    QScopedPointer<Ui::dlgAddNew> ui;
    std::vector<CartItem> &cart;
    CartItem item;
    void addToCart();
    void updateItem(QString id);
    void updateSearch(QString text);
    void itemSelected(QListWidgetItem *item);
};

#endif // ABOUT_ITEMS_H
