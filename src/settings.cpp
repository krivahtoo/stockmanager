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

Settings::Settings (std::string configFile):
    file(configFile)
{}

std::string Settings::getConfigPath()
{
    return "";
}

void Settings::loadSettings()
{}

json Settings::getKey(std::string key)
{
    json val = data[key];
    return val;
}

bool Settings::setKey(std::string key, std::string value)
{
    data[key] = value;
    return 1;
}

std::string Settings::hash(std::string pass)
{
	std::vector<unsigned long> block;
	block = convert_to_binary(pass);
	block = pad_to_512bits(block);
	block = resize_block(block);

	return compute_hash(block);
}

Settings::~Settings () = default;
