#include <iostream>
#include <string>

void printHelpText() {
    std::cout << "Order Book Usage:" << std::endl;
    std::cout << "[help] prints help text" << std::endl;
    std::cout << "[buy]  place buy order" << std::endl;
    std::cout << "[sell] place sell order" << std::endl;
    std::cout << "[exit] terminates the program" << std::endl;
}

int main() {
    printHelpText();

    std::string command;
    std::string buySellString;

    while (command != "exit") {
        std::cout << std::endl << "Please enter a command: ";
        std::cin >> command;

        if (command == "help") {
            printHelpText();
        } else if (command == "buy") {
            std::cout << "Please place the buy order [<Trader> <Stock> <Units>]:" << std::endl;
            ws(std::cin);
            getline(std::cin, buySellString);
            std::cout << buySellString << std::endl;
        } else if (command == "sell") {
            std::cout << "Please place the sell order [<Trader> <Stock> <Units>]:" << std::endl;
            ws(std::cin);
            getline(std::cin, buySellString);
            std::cout << buySellString << std::endl;
        }
    }

    std::cout << "Program terminating." << std::endl;
    return 0;
}
