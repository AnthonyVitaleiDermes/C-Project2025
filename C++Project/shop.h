#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Money.h"
#include "StoreItem.h"
#include "Inventory.h"  

template <typename IDType, typename PriceType>
class Shop {
private:
    class ShopNode {
    public:
        std::string name;
        ShopNode* firstChild;
        ShopNode* nextSibling;
        StoreItem<IDType, PriceType>* item;

        ShopNode(const std::string& n, StoreItem<IDType, PriceType>* item = nullptr)
            : name(n), firstChild(nullptr), nextSibling(nullptr), item(item) {
        }

        void addChild(ShopNode* child) {
            if (!firstChild) {
                firstChild = child;
            }
            else {
                ShopNode* current = firstChild;
                while (current->nextSibling) {
                    current = current->nextSibling;
                }
                current->nextSibling = child;
            }
        }

        void display(int depth = 0) {
            for (int i = 0; i < depth; ++i)
                std::cout << "  ";
            std::cout << name;
            if (item) {
                std::cout << " ($" << item->getPrice() << ")";
            }
            std::cout << std::endl;
            if (firstChild) firstChild->display(depth + 1);
            if (nextSibling) nextSibling->display(depth);
        }

        bool purchaseItem(Money& userMoney, Inventory<IDType, PriceType>& userInventory) {
            if (!item) {
                std::cout << "This item is not available for purchase.\n";
                return false;
            }
            if (userMoney.getAmount() >= item->getPrice()) {
                userMoney.setAmount(userMoney.getAmount() - item->getPrice());
                userInventory.addItem(item, 1); // Add one item to inventory
                std::cout << "Successfully purchased " << item->getName() << " for $" << item->getPrice() << "!\n";
                return true;
            }
            else {
                std::cout << "Insufficient funds to purchase " << item->getName() << ".\n";
                return false;
            }
        }
    };

    class ShopTree {
    public:
        ShopNode* root;
        ShopTree() { root = new ShopNode("Shop"); }

        void buildTree() {
            ShopNode* clothes = new ShopNode("Clothes");
            ShopNode* shirts = new ShopNode("Shirts");
            shirts->addChild(new ShopNode("T-Shirts", new StoreItem<IDType, PriceType>(101, "T-Shirt", 25.0, 10)));
            shirts->addChild(new ShopNode("Dress Shirts", new StoreItem<IDType, PriceType>(102, "Dress Shirt", 40.0, 8)));
            ShopNode* pants = new ShopNode("Pants");
            pants->addChild(new ShopNode("Jeans", new StoreItem<IDType, PriceType>(103, "Jeans", 50.0, 12)));
            pants->addChild(new ShopNode("Chinos", new StoreItem<IDType, PriceType>(104, "Chinos", 45.0, 9)));
            clothes->addChild(shirts);
            clothes->addChild(pants);

            ShopNode* food = new ShopNode("Food");
            ShopNode* fruits = new ShopNode("Fruits");
            fruits->addChild(new ShopNode("Orange", new StoreItem<IDType, PriceType>(201, "Orange", 2.5, 50)));
            fruits->addChild(new ShopNode("Lemon", new StoreItem<IDType, PriceType>(202, "Lemon", 1.8, 40)));
            ShopNode* berries = new ShopNode("Berries");
            berries->addChild(new ShopNode("Strawberry", new StoreItem<IDType, PriceType>(203, "Strawberry", 3.0, 30)));
            berries->addChild(new ShopNode("Blueberry", new StoreItem<IDType, PriceType>(204, "Blueberry", 4.5, 20)));
            food->addChild(fruits);
            food->addChild(berries);

            ShopNode* games = new ShopNode("Games");
            ShopNode* console = new ShopNode("Console");
            ShopNode* xbox = new ShopNode("Xbox");
            ShopNode* xboxOne = new ShopNode("Xbox One");
            xboxOne->addChild(new ShopNode("Halo", new StoreItem<IDType, PriceType>(301, "Halo", 60.0, 10)));
            xboxOne->addChild(new ShopNode("Forza", new StoreItem<IDType, PriceType>(302, "Forza", 55.0, 12)));
            xbox->addChild(xboxOne);
            console->addChild(xbox);

            ShopNode* playstation = new ShopNode("PlayStation");
            ShopNode* ps5 = new ShopNode("PS5");
            ps5->addChild(new ShopNode("Spider-Man", new StoreItem<IDType, PriceType>(303, "Spider-Man", 65.0, 10)));
            ps5->addChild(new ShopNode("God of War", new StoreItem<IDType, PriceType>(304, "God of War", 70.0, 8)));
            playstation->addChild(ps5);
            console->addChild(playstation);
            games->addChild(console);

            root->addChild(clothes);
            root->addChild(food);
            root->addChild(games);
            
        }

        void displayShopMenu(Money& userMoney) {
            std::cout << "Welcome to the shop! Your balance is $" << userMoney.getAmount() << "\n";
            root->display();
        }
    };

    ShopTree shopTree;

public:
    Shop() {
        shopTree.buildTree();
    }

    void displayShopMenu(Money& userMoney) {
        shopTree.displayShopMenu(userMoney);
    }

    void interact(Money& userMoney, Inventory<IDType, PriceType>& userInventory) {
      

        std::cout << "What would you like to buy? ";
        std::cin.ignore();
        std::string selection;
        std::getline(std::cin, selection);

        std::cout << "You have chosen: " << selection << std::endl;
        std::cout << "Would you like to purchase this item? (Y/N): ";

        char response;
        std::cin >> response;

        if (response == 'Y' || response == 'y') {
            ShopNode* itemNode = findItem(shopTree.root, selection);
            if (itemNode && itemNode->item) {
                if (itemNode->purchaseItem(userMoney, userInventory)) {
                    if (removeItem(nullptr, shopTree.root, selection)) {
                        std::cout << selection << " has been removed from the shop.\n";
                    }
                }
            }
            else {
                std::cout << "Item not found or unavailable for purchase.\n";
            }
        }
        else {
            std::cout << "Purchase canceled.\n";
        }
    }

    ShopNode* findItem(ShopNode* node, const std::string& itemName) {
        if (!node) return nullptr;
        if (node->name == itemName && node->item) return node;
        ShopNode* found = findItem(node->firstChild, itemName);
        if (found) return found;
        return findItem(node->nextSibling, itemName);
    }

    bool removeItem(ShopNode* parent, ShopNode* current, const std::string& itemName) {
        if (!current) return false;
        if (current->firstChild && current->firstChild->name == itemName && current->firstChild->item) {
            ShopNode* toDelete = current->firstChild;
            current->firstChild = toDelete->nextSibling;
            delete toDelete->item;
            delete toDelete;
            return true;
        }
        ShopNode* prev = current->firstChild;
        ShopNode* curr = prev ? prev->nextSibling : nullptr;
        while (curr) {
            if (curr->name == itemName && curr->item) {
                prev->nextSibling = curr->nextSibling;
                delete curr->item;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->nextSibling;
        }
        if (removeItem(current, current->firstChild, itemName)) return true;
        return removeItem(current, current->nextSibling, itemName);
    }
};

#endif
