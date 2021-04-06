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

#include <string>

struct Item
{
    int id;
    std::string itemNo; // This can be WR2536 ;-
    std::string name;
    long price;
    long buyingPrice;
    std::string capacity;
    long int entryDate;
};

struct Stock
{
    std::string itemNo;
    int quantity;
};

struct SoldItem
{
    std::string itemNo;
    int quantity;
    std::string paymentMethod;
    long int saleDate;
};

struct CartItem
{
    std::string itemNo;
    std::string name;
    long price;
    int quantity;
    long totalPrice;
};

struct Items
{
    int id;
    std::string itemNo;
    std::string name;
    long price;
    std::string capacity;
    int quantity;
};
