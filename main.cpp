#include <iostream>
#include <string>
#include <sstream>
#include "src/Order.h"
#include "src/OrderBook.h"

using namespace std;

void printHelpText() {
    std::cout << "Order Book Usage:" << std::endl;
    std::cout << "[help]  prints help text" << std::endl;
    std::cout << "[buy]   place buy order" << std::endl;
    std::cout << "[sell]  place sell order" << std::endl;
    std::cout << "[print] print order book" << std::endl;
    std::cout << "[exit]  terminates the program" << std::endl;
}

struct OrderDetails {
    string trader;
    string stock;
    double units;
};

OrderDetails getOrderDetails(const string& side) {
    string buySellString;
    cout << "Please place the " << side << " order [<Trader> <Stock> <Units>]:" << endl;
    ws(cin);
    getline(cin, buySellString);
    istringstream iss(buySellString);
    OrderDetails od;
    iss >> od.trader >> od.stock >> od.units;
    return od;
}

int main() {
    printHelpText();

    string command;
    OrderBook orderBook;

    while (command != "exit") {
        std::cout << std::endl << "Please enter a command: ";
        std::cin >> command;

        if (command == "help") {
            printHelpText();
        } else if (command == "buy") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, true);
            orderBook.buyBook[od.stock].push_back(order);
        } else if (command == "sell") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, false);
            orderBook.sellBook[od.stock].push_back(order);
        } else if (command == "print") {
            cout << orderBook << endl;
        }
    }

    std::cout << "Program terminating." << std::endl;
    return 0;
}
