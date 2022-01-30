#ifndef ORDER_BOOK_ORDERBOOK_H
#define ORDER_BOOK_ORDERBOOK_H

#include <map>
#include <vector>
#include <iostream>
#include "Order.h"

class OrderBook {
public:
    std::map<std::string, std::vector<Order> > buyBook;
    std::map<std::string, std::vector<Order> > sellBook;

    static void printOrderBook(const std::string& side, const std::map<std::string, std::vector<Order> >& book);
    friend std::ostream& operator<<(std::ostream& os, const OrderBook& orderBook);
};

#endif //ORDER_BOOK_ORDERBOOK_H
