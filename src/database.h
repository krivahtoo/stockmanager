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

#ifndef DATABASE_H
#define DATABASE_H

#define SQLITE_HAS_CODEC 1

#include <string>

#include "../sqlite_orm/sqlite_orm.h"

#include "structs.h"

#define DB_FILE "items.db"

inline auto initStorage(const std::string &path) {

    using namespace sqlite_orm;

    return make_storage(path,
        make_table("item",
            make_column("id", &Item::id, autoincrement(), primary_key()),
            make_column("item_no", &Item::itemNo),
            make_column("name", &Item::name),
            make_column("price", &Item::price),
            make_column("buying_price", &Item::buyingPrice),
            make_column("capacity", &Item::capacity),
            make_column("entry_date", &Item::entryDate)
        ),
        make_table("stock",
            make_column("item_no", &Stock::itemNo),
            make_column("quantity", &Stock::quantity)
        ),
        make_table("sold_item",
            make_column("item_no", &SoldItem::itemNo),
            make_column("quantity", &SoldItem::quantity),
            make_column("payment_method", &SoldItem::paymentMethod),
            make_column("sale_date", &SoldItem::saleDate)
        )
    );
}

using Storage = decltype(initStorage(""));

static std::unique_ptr<Storage> storage;

void updateDb();

bool isDbFileExist();

#endif // DATABASE_H
