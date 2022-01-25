#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H

#include <string>
#include <iostream>

using namespace std;

class Order {
public:
    string trader;
    string stock;
    double units;
    bool isBuy;
public:
    Order(string, string, double, bool);
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
};

#endif //ORDER_BOOK_ORDER_H
