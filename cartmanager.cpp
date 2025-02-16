#include "cartmanager.hpp"

CartManager::CartManager() {

}

void CartManager::add_item(const Item &item) {
    for(Item &existing_item : items){
        if(existing_item.name == item.name){
            existing_item.quantity += item.quantity;

            return;
        }
    }
    items.append(item);
}

void CartManager::remove_item(const QString &item_name) {
    for(size_t i {0}; i < items.size(); ++i){
        if(items[i].name == item_name){
            items.removeAt(i);

            return;
        }
    }
}

double CartManager::calc_cart() const {
    double total {0};

    for(const Item &item: items){
        total += item.total();
    }

    return total;
}

QList<Item>::iterator CartManager::begin() {
    return items.begin();
}

QList<Item>::iterator CartManager::end() {
    return items.end();
}

QList<Item>::const_iterator CartManager::begin() const {
    return items.begin();
}

QList<Item>::const_iterator CartManager::end() const {
    return items.end();
}
