#ifndef ORDER_BOOK_ORDERBOOK_H
#define ORDER_BOOK_ORDERBOOK_H

#include <map>
#include <vector>
#include <iostream>
#include "Order.h"

using namespace std;

class OrderBook {
public:
    map<string, vector<Order>> buyBook;
    map<string, vector<Order>> sellBook;
    static void printOrderBook(const string& side, const map<string, vector<Order>>& book);
public:
    OrderBook();
    friend std::ostream& operator<<(std::ostream& os, const OrderBook& orderBook);
};

#endif //ORDER_BOOK_ORDERBOOK_H
