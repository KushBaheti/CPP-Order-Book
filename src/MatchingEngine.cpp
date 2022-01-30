#include "OrderBook.h"
#include "MatchingEngine.h"

void orderExecutedMessage(const std::string& trader, const std::string& oppositeTrader, const std::string& stock, double units, bool isBuy) {
    std::string buyTrader = isBuy ? trader : oppositeTrader;
    std::string sellTrader = isBuy ? oppositeTrader : trader;

    std::cout << "Order Executed - ";
    std::cout << "Buy: " << buyTrader
              << " Stock: " << stock
              << " Units: " << units
              << " Sell: " << sellTrader
              << std::endl;
}

void MatchingEngine::run(const Order& order) {
    auto [ trader, stock, units, isBuy ] = order;

    std::map<std::string, std::vector<Order>> &book = isBuy ? orderBook.buyBook : orderBook.sellBook;
    std::map<std::string, std::vector<Order>> &oppositeBook = isBuy ? orderBook.sellBook : orderBook.buyBook;

    if (oppositeBook[stock].empty()) {
        book[stock].push_back(order);
        return;
    }

    auto itr = oppositeBook[stock].begin();
    double matchQty;

    while (itr != oppositeBook[stock].end()) {
        matchQty = std::min(units, itr->units);
        units -= matchQty;
        itr->units -= matchQty;

        orderExecutedMessage(trader, itr->trader, stock, matchQty, isBuy);

        if (itr->units == 0) {
            itr = oppositeBook[stock].erase(itr);
        } else {
            ++itr;
        }

        if (units == 0) {
            break;
        }
    }

    if (units != 0) {
        Order updatedOrder = Order(trader, stock, units, isBuy);
        book[stock].push_back(updatedOrder);
    }
}
