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
#include "settings.h"
#include "utils.h"

#include <sqlcipher/sqlite3.h>

#include <QtCore/QFile>

void updateDb() {
  storage = std::make_unique<Storage>(initStorage(util::getDBPath(DB_FILE)));
  storage->on_open = [&](sqlite3 *db) {
    sqlite3_key(db, Settings::getInstance().db_key.c_str(),
                Settings::getInstance().db_key.size());
  };
  storage->sync_schema();
}

bool isDbFileExist() {
  return QFile::exists(QString::fromStdString(util::getDBPath(DB_FILE)));
}
