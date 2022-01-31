# C++ Order Book

## Project Description
This project is a minimalistic working application of an open order book and matching engine using C++ and its standard libraries.

## Table of Contents
* [Project Description](#project-description)
* [Table of Contents](#table-of-contents)
* [Technology](#technology)
* [Installation](#installation)
* [Features](#features)
* [Examples of use](#examples-of-use)
* [Implementation](#implementation)
* [Tests](#tests)
* [TODO](#todo)

## Technology
C++ 17\
Google Test v1.11.0

## Installation
Clone the project and navigate into the project directory.
Compile the project by running the command: 
```bash
make
```
This will create an exectuable `orderBook`, which can be run by entering the command:
```bash
./orderBook
```

## Features
The program consists of two main entities:
1. An order book, which stores open (unexecuted) orders only.
2. A matching engine, which matches new orders against orders stored in the order book, and notifies the traders if the order is fully or partially filled.

Once the program is run, an interactive repl is started.
The repl allows the user to place buy and sell orders, and print the open orders in the order book.\
Currently, the program does not take into account the price of the stock, and simply matches orders based on quantity.

## Examples of use
For example, a buy order can be placed by simply specifying the trader name, stock the trader the wishes to purchase, and the desired quantity:
```bash
Please enter a command: buy
Please place the buy order [<Trader> <Stock> <Units>]:
BUYTRADER GOOG 10
```
Similarly, a sell order can be placed as follows:
```bash
Please enter a command: sell
Please place the sell order [<Trader> <Stock> <Units>]:
SELLTRADER GOOG 12
```
This sell order will match with the already existing buy order for 10 units of GOOG. A message to notify the traders will be printed as below:
```bash
[Order Executed] Buy: BUYTRADER | Stock: GOOG Units: 10 | Sell: SELLTRADER
```
And printing the order book would show an empty buy book, as the buy order was completely filled, and one open order on the sell book, as the sell order was only partially filled.
```bash
Please enter a command: book
Buy Book:
Stock: GOOG
Orders: 

Sell Book:
Stock: GOOG
Orders: 
Trader: SELLTRADER; Stock: GOOG; Units: 2
```

## Implementation
The `Order` class serves as the most fundamental unit.

The `OrderBook` class consists of two `std::maps`, which represent the buy book and the sell book. The key of the map is the stock ticker/name, and the value is a vector of `Order`'s.
Thus, the data structure of the buy and sell book looks like: `std::map<std::string, std::vector<Order>>`.

The `MatchingEngine` class instantiates an `OrderBook` object. It runs everytime a new `Order` has been placed. It is responsible for checking whether an open order of the opposite position exists, executing the trade, and printing the notification.

## Tests
The `MatchingEngine` was implemented by following TDD, and includes tests written using the Google Test library.

## TODO
* Update Makefile to be able to build Google Tests.
* Explore use of `std::deque` and `std::list` (instead of `std::vector`) to store orders. 
* Include price as part of order, and match incoming orders to the best price possible.