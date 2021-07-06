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

#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

struct Item
{
    int id;
    std::string itemNo; // This can be WR2536 ;-
    std::string name;
    long price;
    long minimumPrice;
    long buyingPrice;
    std::string capacity;
    long int entryDate;
    // TODO: implement photo
    std::unique_ptr<std::string> photo;
};

struct Stock
{
    std::string itemNo;
    int quantity;
    std::unique_ptr<long int> lastStocked;
};

struct SoldItem
{
    int id;
    std::string itemNo;
    int quantity;
    // TODO: use enum
    std::string paymentMethod;
    long int saleDate;
    std::unique_ptr<long> sellingPrice;
    std::unique_ptr<int> userId;
};

// TODO: implement user login
struct User
{
    int id;
    std::string username;
    std::string name;
    std::string password;
    std::string role;
    std::unique_ptr<std::string> avatar;
    std::unique_ptr<long int> lastLogin;
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

#endif // STRUCTS_H
