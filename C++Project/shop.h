#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Money.h"
#include "StoreItem.h" 

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

        bool purchaseItem(Money& userMoney) {
            if (!item) {
                std::cout << "This item is not available for purchase.\n";
                return false;
            }
            if (userMoney.getAmount() >= item->getPrice()) {
                userMoney.setAmount(userMoney.getAmount() - item->getPrice());
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
            ShopNode* tShirts = new ShopNode("T-Shirts", new StoreItem<IDType, PriceType>(101, "T-Shirt", 25.0, 10));
            ShopNode* dressShirts = new ShopNode("Dress Shirts", new StoreItem<IDType, PriceType>(102, "Dress Shirt", 40.0, 8));
            shirts->addChild(tShirts);
            shirts->addChild(dressShirts);
            ShopNode* pants = new ShopNode("Pants");
            ShopNode* jeans = new ShopNode("Jeans", new StoreItem<IDType, PriceType>(103, "Jeans", 50.0, 12));
            ShopNode* chinos = new ShopNode("Chinos", new StoreItem<IDType, PriceType>(104, "Chinos", 45.0, 9));
            pants->addChild(jeans);
            pants->addChild(chinos);
            clothes->addChild(shirts);
            clothes->addChild(pants);

            ShopNode* food = new ShopNode("Food");
            ShopNode* fruits = new ShopNode("Fruits");
            ShopNode* orange = new ShopNode("Orange", new StoreItem<IDType, PriceType>(201, "Orange", 2.5, 50));
            ShopNode* lemon = new ShopNode("Lemon", new StoreItem<IDType, PriceType>(202, "Lemon", 1.8, 40));
            fruits->addChild(orange);
            fruits->addChild(lemon);
            ShopNode* berries = new ShopNode("Berries");
            ShopNode* strawberry = new ShopNode("Strawberry", new StoreItem<IDType, PriceType>(203, "Strawberry", 3.0, 30));
            ShopNode* blueberry = new ShopNode("Blueberry", new StoreItem<IDType, PriceType>(204, "Blueberry", 4.5, 20));
            berries->addChild(strawberry);
            berries->addChild(blueberry);
            food->addChild(fruits);
            food->addChild(berries);

            ShopNode* games = new ShopNode("Games");
            ShopNode* console = new ShopNode("Console");
            ShopNode* xbox = new ShopNode("Xbox");
            ShopNode* xboxOne = new ShopNode("Xbox One");
            ShopNode* halo = new ShopNode("Halo", new StoreItem<IDType, PriceType>(301, "Halo", 60.0, 10));
            ShopNode* forza = new ShopNode("Forza", new StoreItem<IDType, PriceType>(302, "Forza", 55.0, 12));
            xboxOne->addChild(halo);
            xboxOne->addChild(forza);
            xbox->addChild(xboxOne);
            console->addChild(xbox);
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
    Shop() { shopTree.buildTree(); }

    void displayShopMenu(Money& userMoney) { shopTree.displayShopMenu(userMoney); }

    void interact(Money& userMoney) {
        displayShopMenu(userMoney);

        std::cout << "What would you like to buy? ";
        std::string selection;
        std::getline(std::cin >>  selection); 

        std::cout << "You have chosen: " << selection << std::endl;
        std::cout << "Would you like to purchase this item? (Y/N) ";

        char response;
        std::cin >> response;
     

        if (response == 'Y' || response == 'y') {
            ShopNode* itemNode = findItem(shopTree.root, selection);
            if (itemNode && itemNode->item) {
                itemNode->purchaseItem(userMoney);
            }
            else {
                std::cout << "Item not found or unavailable for purchase.\n";
            }
        }
        else {
            std::cout << "Purchase canceled.\n";
        }
    }

    // Recursion
    ShopNode* findItem(ShopNode* node, const std::string& itemName) {
        if (!node) return nullptr;

        if (node->name == itemName && node->item) return node;

        ShopNode* found = findItem(node->firstChild, itemName);
        if (found) return found;

        return findItem(node->nextSibling, itemName);
    }
};

#endif