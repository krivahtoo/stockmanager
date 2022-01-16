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
#include "settings.h"

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

#include <string>
#include <algorithm>

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QStandardPaths>

namespace util
{
    std::string formatCurrency(std::string price)
    {
        using json = nlohmann::json;
        Settings settings;
        json data = settings.getKey("currency");
        data["price"] = price;
        return inja::render("{{ prefix }}{{ price }}{{ suffix }}", data);
    }

    std::string formatNumber(int number)
    {
        auto src = std::to_string(number);
        auto dest = std::string();
        auto count = 3;
        for(auto i = src.crbegin() ; i != src.crend() ; ++i) {
            if (count == 0) {
                dest.push_back(',');
                count = 3;
            }
            if (count--) {
                dest.push_back(*i);
            }
        }
        std::reverse(dest.begin(), dest.end());

        return dest;
    }

    std::string getDBPath(QString file)
    {
        QDir dir;
        QString path = QStandardPaths::locate(
            QStandardPaths::AppDataLocation,
            QString("data"), QStandardPaths::LocateDirectory
        );
        if (path.isEmpty()) {
            dir = QDir(
                QStandardPaths::standardLocations(
                    QStandardPaths::AppDataLocation
                ).first()
            );
            if (!dir.exists())
                qWarning("Cannot find the data directory");
            QDir hdir = QDir::home();
            if (
                !hdir.mkpath(
                    QStandardPaths::standardLocations(
                        QStandardPaths::AppDataLocation
                    ).first()
                )
            ) qWarning("Could not create data directory");
                
            dir.mkdir("data");
            dir.cd("data");
        } else {
            dir = QDir(path);
        }
        path = dir.filePath(file);
        return path.toStdString();
    }

    QDir getBackupPath()
    {
        QDir dir;
        QString path = QStandardPaths::locate(
            QStandardPaths::AppDataLocation,
            QString("backups"), QStandardPaths::LocateDirectory
        );
        if (path.isEmpty()) {
            dir = QDir(
                QStandardPaths::standardLocations(
                    QStandardPaths::AppDataLocation
                ).first()
            );
            if (!dir.exists())
                qWarning("Cannot find the backups directory");
            QDir hdir = QDir::home();
            if (
                !hdir.mkpath(
                    QStandardPaths::standardLocations(
                        QStandardPaths::AppDataLocation
                    ).first()
                )
            ) qWarning("Could not create backups directory");
                
            dir.mkdir("backups");
            dir.cd("backups");
        } else {
            dir = QDir(path);
        }
        return dir;
    }
}
