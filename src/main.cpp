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

#include "stock_manager.h"
#include "database.h"
#include "settings.h"
#include "version.h"

#include <QtCore/QFile>
#include <QtWidgets/QApplication>
#include <QtWidgets/QInputDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationDisplayName("Shop Manager");
    app.setApplicationName("StockManager");
    app.setApplicationVersion(VERSION);
    app.setOrganizationName("KrivArt");
    Settings settings;
    QFile config_file;
    config_file.setFileName(QString::fromStdString(Settings::config_path));
    // TODO: Find a better way / implement user login
    if (!isDbFileExist() || !config_file.exists()) {
        bool ok = false;
        QString pass = "";
        QString confirm = "";
        while ((!ok && pass.isEmpty()) || pass != confirm) {
            pass = QInputDialog::getText(nullptr,
                "Set Master password", "Password",
                QLineEdit::Password,
                "", &ok
            );
            confirm = QInputDialog::getText(nullptr,
                "Confirm Master password", "Confirm Password",
                QLineEdit::Password
            );
        }
        settings.setDBKey(pass.toStdString());
        settings.setKey("db_key", Settings::hash(pass.toStdString()));
    } else {
        bool ok = false;
        bool correct = false;
        QString pass = "";
        while (pass.isEmpty() || !correct) {
            pass = QInputDialog::getText(nullptr,
                "Enter Master Password", "Password",
                QLineEdit::Password,
                "", &ok
            );
            if (Settings::hash(pass.toStdString()) == settings.getKey("db_key").get<std::string>())
                correct = true;
            
            if (!ok) exit(1);
        }
        settings.setDBKey(pass.toStdString());
    }
    settings.saveSettings();
    updateDb();
    stock_manager w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return app.exec();
}
