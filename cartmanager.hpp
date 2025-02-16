#ifndef CARTMANAGER_HPP
#define CARTMANAGER_HPP

#include "item.hpp"

#include <QList>

class CartManager {

private:
    QList <Item> items;

public:
    CartManager();

    void add_item(const Item &item);
    void remove_item(const QString &item_name);

    double calc_cart() const;

    QList<Item>::iterator begin();
    QList<Item>::iterator end();
    QList<Item>::const_iterator begin() const;
    QList<Item>::const_iterator end() const;

};

#endif // CARTMANAGER_HPP
