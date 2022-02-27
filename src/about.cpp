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

#include "about.h"

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

dlgAbout::dlgAbout(QMainWindow *parent)
    : QDialog(parent), ui(new Ui::dlgAbout) {
  json j;
  ui->setupUi(this);

  j["name"] = NAME;
  j["about"] = ABOUT;
  j["version"] = VERSION;
  j["author"] = AUTHOR;

  ui->label->setText(QString::fromStdString(inja::render(R"(
<html>
<head/>
<body>
  <p><span style=" font-size:14pt; font-weight:600;">{{ name }}</span></p>
  <p>{{ about }}</p>
  <p><span style=" font-weight:600;">Version:</span> {{ version }}</p>
  <p><span style=" font-style:italic;">{{ author }}</span></p>
</body>
</html>)",
                                                         j)));
}

dlgAbout::~dlgAbout() = default;
