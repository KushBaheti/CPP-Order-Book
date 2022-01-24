#include "Order.h"

Order::Order(string _trader, string _stock, double _units, bool _isBuy) {
    trader = _trader;
    stock = _stock;
    units = _units;
    isBuy = _isBuy;
}
