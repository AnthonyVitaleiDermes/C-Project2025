#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include <stack>
#include "Money.h"
#include "StoreItem.h"

// template class for the shop
template <typename IDType, typename PriceType>
class Shop {
private:
    // private class for shop node which represents each category or item
    class ShopNode {
    public:
        std::string name;
		ShopNode* firstChild; // pointer to the first child node
		ShopNode* nextSibling; // pointer to the next sibling node
		StoreItem<IDType, PriceType>* item; // pointer to the item (if any)

        // constructor for shop node
        ShopNode(const std::string& n, StoreItem<IDType, PriceType>* item = nullptr)
            : name(n), firstChild(nullptr), nextSibling(nullptr), item(item) {
        }

        // function to add a child node to the current node
        void addChild(ShopNode* child) {
			if (!firstChild) { // if no children exist
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

        // function to display the node and its children
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

        // function to handle purchase logic
        bool purchaseItem(Money& userMoney) {
            if (!item) {
                std::cout << "this item is not available for purchase.\n";
                return false;
            }
            if (userMoney.getAmount() >= item->getPrice()) {
                userMoney.setAmount(userMoney.getAmount() - item->getPrice());
                std::cout << "successfully purchased " << item->getName()
                    << " for $" << item->getPrice() << "!\n";
                return true;
            }
            else {
                std::cout << "insufficient funds to purchase " << item->getName() << ".\n";
                return false;
            }
        }
    };

    // private class to manage the shop tree structure
    class ShopTree {
    public:
        ShopNode* root;

        // constructor initializing root node as the shop
        ShopTree() {
            root = new ShopNode("Shop");
        }

        // function to build the shop tree with categories and items
        void buildTree() {

            //clothes section
            ShopNode* clothes = new ShopNode("Clothes");
            ShopNode* shirts = new ShopNode("Shirts");
            shirts->addChild(new ShopNode("T-Shirts", new StoreItem<IDType, PriceType>(101, "T-Shirt", 25.0, 10)));
            shirts->addChild(new ShopNode("Dress Shirts", new StoreItem<IDType, PriceType>(102, "Dress Shirt", 40.0, 8)));
            ShopNode* pants = new ShopNode("Pants");
            pants->addChild(new ShopNode("Jeans", new StoreItem<IDType, PriceType>(103, "Jeans", 50.0, 12)));
            pants->addChild(new ShopNode("Jorts", new StoreItem<IDType, PriceType>(104, "Jorts", 45.0, 9)));
            clothes->addChild(shirts);
            clothes->addChild(pants);
			//food section
            ShopNode* food = new ShopNode("Food");
            ShopNode* fruits = new ShopNode("Fruits");
            fruits->addChild(new ShopNode("Orange", new StoreItem<IDType, PriceType>(201, "Orange", 2.5, 50)));
            fruits->addChild(new ShopNode("Lemon", new StoreItem<IDType, PriceType>(202, "Lemon", 1.8, 40)));
            ShopNode* berries = new ShopNode("Berries");
            berries->addChild(new ShopNode("Strawberry", new StoreItem<IDType, PriceType>(203, "Strawberry", 3.0, 30)));
            berries->addChild(new ShopNode("Blueberry", new StoreItem<IDType, PriceType>(204, "Blueberry", 4.5, 20)));
            food->addChild(fruits);
            food->addChild(berries);
			//games section
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

        // function to display the shop menu with user's balance
        void displayShopMenu(Money& userMoney) {
            std::cout << "welcome to the shop! your balance is $" << userMoney.getAmount() << "\n";
            root->display();
        }
    };

    // object representing the shop tree and purchase history stack
    ShopTree shopTree;
    std::stack<StoreItem<IDType, PriceType>*> purchaseHistory;

public:
    // constructor to build the shop tree when the shop is created
    Shop() {
        shopTree.buildTree();
    }

    // function to display the shop menu
    void displayShopMenu(Money& userMoney) {
        shopTree.displayShopMenu(userMoney);
    }

    // function to interact with the user and process a purchase
    StoreItem<IDType, PriceType>* interact(Money& userMoney) {
        std::cin.ignore();
        std::string selection;
        std::cout << "what would you like to buy? once purchased, it won't be available again: ";
        std::getline(std::cin, selection);

        std::cout << "you have chosen: " << selection << std::endl;
        std::cout << "would you like to purchase this item? (Y/N): ";
        char response;
        std::cin >> response;

        if (response == 'Y' || response == 'y') {
            ShopNode* itemNode = findItem(shopTree.root, selection);
            if (itemNode && itemNode->item) {
                if (itemNode->purchaseItem(userMoney)) {
                    StoreItem<IDType, PriceType>* purchasedItem = itemNode->item;
                    itemNode->item = nullptr;
                    purchaseHistory.push(purchasedItem);

                    // remove the item from the tree
                    removeItemNode(shopTree.root, selection);

                    return purchasedItem;
                }
            }
            else {
                std::cout << "item not found or unavailable for purchase.\n";
            }
        }
        else {
            std::cout << "purchase canceled.\n";
        }
        return nullptr;
    }


    // function to display the user's purchase history
    void displayPurchaseHistory() {
        std::stack<StoreItem<IDType, PriceType>*> temp = purchaseHistory;
        if (temp.empty()) {
            std::cout << "no items purchased yet.\n";
            return;
        }

        std::cout << "purchase history:\n";
        while (!temp.empty()) {
            StoreItem<IDType, PriceType>* item = temp.top();
            temp.pop();
            std::cout << "- " << item->getName() << " ($" << item->getPrice() << ")\n";
        }
    }

private:
    // function to find an item in the shop tree
    ShopNode* findItem(ShopNode* node, const std::string& itemName) {
        if (!node) return nullptr;
        if (node->name == itemName && node->item) return node;
        ShopNode* found = findItem(node->firstChild, itemName);
        if (found) return found;
        return findItem(node->nextSibling, itemName);
    }

    // function to remove an item node from the shop tree
    void removeItemNode(ShopNode* parent, const std::string& itemName) {
        if (!parent) return;

        ShopNode* prev = nullptr;
        ShopNode* current = parent->firstChild;

        while (current) {
            if (current->name == itemName) {
                if (prev) {
                    prev->nextSibling = current->nextSibling;
                }
                else {
                    parent->firstChild = current->nextSibling;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->nextSibling;
        }

        // recurse through children
        removeItemNode(parent->firstChild, itemName);
        removeItemNode(parent->nextSibling, itemName);
    }
};

#endif
