#include <iostream>
#include <string>
#include <sstream>
#include "src/Order.h"

using namespace std;

void printHelpText() {
    std::cout << "Order Book Usage:" << std::endl;
    std::cout << "[help] prints help text" << std::endl;
    std::cout << "[buy]  place buy order" << std::endl;
    std::cout << "[sell] place sell order" << std::endl;
    std::cout << "[exit] terminates the program" << std::endl;
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

    std::string command;

    while (command != "exit") {
        std::cout << std::endl << "Please enter a command: ";
        std::cin >> command;

        if (command == "help") {
            printHelpText();
        } else if (command == "buy") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, true);
        } else if (command == "sell") {
            OrderDetails od = getOrderDetails(command);
            Order order = Order(od.trader, od.stock, od.units, false);
        }
    }

    std::cout << "Program terminating." << std::endl;
    return 0;
}
