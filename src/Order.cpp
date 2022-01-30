#include "Order.h"

Order::Order(std::string _trader, std::string _stock, double _units, bool _isBuy) {
    trader = _trader;
    stock = _stock;
    units = _units;
    isBuy = _isBuy;
}

std::ostream &operator<<(std::ostream &os, const Order& order) {
    std::cout << "Trader: " << order.trader << "; ";
    std::cout << "Stock: " << order.stock << "; ";
    std::cout << "Units: " << order.units;
    return os;
}

bool operator==(const Order& lhs, const Order& rhs) {
    return lhs.trader == rhs.trader &&
           lhs.stock == rhs.stock &&
           lhs.units == rhs.units &&
           lhs.isBuy == rhs.isBuy;
}
