#ifndef ITEM_HPP
#define ITEM_HPP

#include <QString>

class Item {

private:
    static constexpr const char *def_name {"Item"};
    static constexpr double def_price {0.0};
    static constexpr double def_quantity {0};

public:
    QString name;
    double price;
    int quantity;

    Item(QString name = def_name, double price = def_price, int quantity = def_quantity);

    double total() const;
};

#endif // ITEM_HPP
