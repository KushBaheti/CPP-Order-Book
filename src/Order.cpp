#include "Order.h"

Order::Order(string _trader, string _stock, double _units, bool _isBuy) {
    trader = _trader;
    stock = _stock;
    units = _units;
    isBuy = _isBuy;
}

ostream &operator<<(ostream &os, const Order& order) {
    cout << "Trader: " << order.trader << "; ";
    cout << "Stock: " << order.stock << "; ";
    cout << "Units: " << order.units;
    return os;
}
