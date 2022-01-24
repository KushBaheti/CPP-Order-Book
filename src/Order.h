#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H

#include <string>

using namespace std;

class Order {
public:
    string trader;
    string stock;
    double units;
    bool isBuy;
public:
    Order(string, string, double, bool);
};

#endif //ORDER_BOOK_ORDER_H
