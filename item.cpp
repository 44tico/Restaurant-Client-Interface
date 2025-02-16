#include "item.hpp"

Item::Item(QString name, double price, int quantity)
    : name {name}, price {price}, quantity {quantity} {
}

double Item::total() const{
    return price * quantity;
}
