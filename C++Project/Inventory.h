#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <list>  
#include <string>
#include "StoreItem.h"

template <typename IDType, typename PriceType>
class Inventory {
private:
    struct InventoryItem {
        StoreItem<IDType, PriceType>* item;
        int quantity;

        InventoryItem(StoreItem<IDType, PriceType>* item, int quantity)
            : item(item), quantity(quantity) {
        }
    };

    std::list<InventoryItem> items;  

public:
    // Add item to inventory
    void addItem(StoreItem<IDType, PriceType>* item, int quantity) {
        for (auto& inventoryItem : items) {
            if (inventoryItem.item->getName() == item->getName()) {
                inventoryItem.quantity += quantity;
                return;
            }
        }
        items.push_back({ item, quantity });
    }

    // Display inventory
    void displayInventory() const {
        std::cout << "\nYour Inventory:\n";
        for (const auto& inventoryItem : items) {
            std::cout << inventoryItem.item->getName() << " x" << inventoryItem.quantity << '\n';
        }
    }

    // Remove item from inventory
    bool removeItem(const std::string& itemName, int quantity) {
        for (auto& inventoryItem : items) {
            if (inventoryItem.item->getName() == itemName) {
                if (inventoryItem.quantity >= quantity) {
                    inventoryItem.quantity -= quantity;
                    return true;
                }
                std::cout << "Not enough quantity in inventory.\n";
                return false;
            }
        }
        std::cout << "Item not found in inventory.\n";
        return false;
    }

    // Check if item exists in inventory
    bool hasItem(const std::string& itemName, int quantity) const {
        for (const auto& inventoryItem : items) {
            if (inventoryItem.item->getName() == itemName) {
                return inventoryItem.quantity >= quantity;
            }
        }
        return false;
    }
};

#endif
