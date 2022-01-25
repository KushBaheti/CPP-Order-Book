#include "OrderBook.h"

using namespace std;

OrderBook::OrderBook() {

}

void OrderBook::printOrderBook(const string &side, const map<string, vector<Order>> &book) {
    cout << side << " Book:" << endl;
    for (auto const &pair: book) {
        cout << "Stock: " << pair.first << endl;
        cout << "Orders: " << endl;
        for (const Order& order: pair.second) {
            cout << order << endl;
        }
        cout << endl;
    }
}

ostream &operator<<(ostream &os, const OrderBook& orderBook) {
    OrderBook::printOrderBook("Buy", orderBook.buyBook);
    OrderBook::printOrderBook("Sell", orderBook.sellBook);
    return os;
}
