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

#ifndef SETTINGS_H
#define SETTINGS_H

#include "structs.h"

#include <nlohmann/json.hpp>

#include <string>

using json = nlohmann::json;

class Settings {
private:
  Settings(std::string configFile = "config.json");
  json data;
  User *user;
  std::string file;
  std::string getConfigPath();
  void loadSettings();

public:
  std::string db_key;
  std::string config_path;
  json getKey(std::string key);
  bool setKey(std::string key, std::string value);
  void saveSettings();
  void setDBKey(std::string dbKey);
  User *getUser();
  void setUser(User *user);
  static Settings &getInstance();
  Settings(Settings const &) = delete;
  void operator=(Settings const &) = delete;
};

#endif // SETTINGS_H
