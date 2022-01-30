#ifndef ORDER_BOOK_ORDER_H
#define ORDER_BOOK_ORDER_H

#include <string>
#include <iostream>

class Order {
public:
    std::string trader;
    std::string stock;
    double units;
    bool isBuy;

    Order(std::string, std::string, double, bool);
    friend std::ostream& operator<<(std::ostream& os, const Order& order);
    friend bool operator==(const Order& lhs, const Order& rhs);
};

#endif //ORDER_BOOK_ORDER_H
