#include <iostream>
#include <string>
#include <sstream>
#include "src/Order.h"
#include "src/OrderDetails.h"
#include "src/OrderBook.h"
#include "src/MatchingEngine.h"

void printHelpText();
OrderDetails getOrderDetails(const std::string& side);

int main() {
    printHelpText();

    std::string command;
    MatchingEngine engine;

    while (command != "exit") {
        std::cout << std::endl << "Please enter a command: ";
        std::cin >> command;

        if (command == "help") {
            printHelpText();
        } else if (command == "buy") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, true);
            engine.run(order);
        } else if (command == "sell") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, false);
            engine.run(order);
        } else if (command == "print") {
            std::cout << engine.orderBook << std::endl;
        }
    }

    std::cout << "Program terminating." << std::endl;
    return 0;
}

void printHelpText() {
    std::cout << "Order Book Usage:" << std::endl;
    std::cout << "[help]  prints help text" << std::endl;
    std::cout << "[buy]   place buy order" << std::endl;
    std::cout << "[sell]  place sell order" << std::endl;
    std::cout << "[print] print order book" << std::endl;
    std::cout << "[exit]  terminates the program" << std::endl;
}

OrderDetails getOrderDetails(const std::string& side) {
    std::string buySellString;
    std::cout << "Please place the " << side << " order [<Trader> <Stock> <Units>]:" << std::endl;
    ws(std::cin);
    getline(std::cin, buySellString);
    std::istringstream iss(buySellString);
    OrderDetails od;
    iss >> od.trader >> od.stock >> od.units;
    for (char &c: od.trader) c = toupper(c);
    for (char &c: od.stock) c = toupper(c);
    return od;
}
