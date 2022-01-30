#include "OrderBook.h"

void OrderBook::printOrderBook(const std::string &side, const std::map<std::string, std::vector<Order>> &book) {
    std::cout << side << " Book:" << std::endl;
    for (auto const &pair: book) {
        std::cout << "Stock: " << pair.first << std::endl;
        std::cout << "Orders: " << std::endl;
        for (const Order& order: pair.second) {
            std::cout << order << std::endl;
        }
        std::cout << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const OrderBook& orderBook) {
    OrderBook::printOrderBook("Buy", orderBook.buyBook);
    OrderBook::printOrderBook("Sell", orderBook.sellBook);
    return os;
}
