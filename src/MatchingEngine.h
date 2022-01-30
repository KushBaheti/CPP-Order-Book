#ifndef ORDER_BOOK_MATCHINGENGINE_H
#define ORDER_BOOK_MATCHINGENGINE_H

#include <string>
#include <iostream>
#include "OrderBook.h"

class MatchingEngine {
public:
    OrderBook orderBook;

    void run(const Order&);
};

#endif //ORDER_BOOK_MATCHINGENGINE_H
