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

#include "settings.h"
#include "sha256.h"

#include <fstream>

#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QStandardPaths>
#include <QtCore/QString>

Settings::Settings(std::string configFile) : file(configFile) {
  config_path = "";
  db_key = "";
  user_id = 0;

  loadSettings();
}

std::string Settings::getConfigPath() {
  QString path = QStandardPaths::locate(QStandardPaths::AppConfigLocation,
                                        QString::fromStdString(file),
                                        QStandardPaths::LocateFile);
  if (path.isEmpty()) {
    QDir dir = QDir(
        QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)
            .first());
    if (!dir.exists())
      qWarning("Cannot find the config directory");
    QDir hdir = QDir::home();
    if (!hdir.mkpath(
            QStandardPaths::standardLocations(QStandardPaths::AppConfigLocation)
                .first()))
      qWarning("Could not create config directory");

    path = dir.filePath(QString::fromStdString(file));
  }
  return path.toStdString();
}

void Settings::loadSettings() {
  QFile file;
  file.setFileName(QString::fromStdString(getConfigPath()));
  config_path = getConfigPath();
  if (!file.exists()) {
    data = {{"name", "Shop Manager"},
            {"theme", "default"},
            {"currency", {{"prefix", "Ksh. "}, {"suffix", ".00"}}}};
    return;
  }

  std::ifstream i(getConfigPath());
  i >> data;
  i.close();
}

void Settings::saveSettings() {
  std::ofstream o(getConfigPath());
  o << std::setw(4) << data << std::endl;
  o.close();
}

json Settings::getKey(std::string key) {
  json val;
  if (!data.contains(key))
    return val;
  val = data[key];
  return val;
}

bool Settings::setKey(std::string key, std::string value) {
  data[key] = value;
  return 1;
}

User *Settings::getUser() { return this->user; }

void Settings::setUser(User *user) { this->user = user; }

void Settings::setDBKey(std::string dbKey) { Settings::db_key = dbKey; }

void Settings::setUserId(int id) { Settings::user_id = id; }

Settings &Settings::getInstance() {
  static Settings instance;
  return instance;
}
