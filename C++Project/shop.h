#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Money.h"

class Shop {
private:
    class ShopNode {
    public:
        std::string name;
        ShopNode* firstChild;
        ShopNode* nextSibling;

        ShopNode(const std::string& n) : name(n), firstChild(nullptr), nextSibling(nullptr) {}

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
            std::cout << name << std::endl;
            if (firstChild)
                firstChild->display(depth + 1);
            if (nextSibling)
                nextSibling->display(depth);
        }
    };

    class ShopTree {
    public: // this was so long for no reason
        ShopNode* root;

        ShopTree() { root = new ShopNode("Shop"); }

        void buildTree() {
            ShopNode* clothes = new ShopNode("Clothes");
            ShopNode* shirts = new ShopNode("Shirts");
            ShopNode* tShirts = new ShopNode("T-Shirts");
            ShopNode* dressShirts = new ShopNode("Dress Shirts");
            shirts->addChild(tShirts);
            shirts->addChild(dressShirts);
            ShopNode* pants = new ShopNode("Pants");
            ShopNode* jeans = new ShopNode("Jeans");
            ShopNode* chinos = new ShopNode("Chinos");
            pants->addChild(jeans);
            pants->addChild(chinos);
            clothes->addChild(shirts);
            clothes->addChild(pants);

            ShopNode* food = new ShopNode("Food");
            ShopNode* fruits = new ShopNode("Fruits");
            ShopNode* citrus = new ShopNode("Citrus");
            ShopNode* orange = new ShopNode("Orange");
            ShopNode* lemon = new ShopNode("Lemon");
            citrus->addChild(orange);
            citrus->addChild(lemon);
            ShopNode* berries = new ShopNode("Berries");
            ShopNode* strawberry = new ShopNode("Strawberry");
            ShopNode* blueberry = new ShopNode("Blueberry");
            berries->addChild(strawberry);
            berries->addChild(blueberry);
            fruits->addChild(citrus);
            fruits->addChild(berries);
            ShopNode* snacks = new ShopNode("Snacks");
            ShopNode* chips = new ShopNode("Chips");
            ShopNode* potatoChips = new ShopNode("Potato Chips");
            ShopNode* tortillaChips = new ShopNode("Tortilla Chips");
            chips->addChild(potatoChips);
            chips->addChild(tortillaChips);
            ShopNode* candy = new ShopNode("Candy");
            ShopNode* chocolate = new ShopNode("Chocolate");
            ShopNode* hardCandy = new ShopNode("Hard Candy");
            candy->addChild(chocolate);
            candy->addChild(hardCandy);
            snacks->addChild(chips);
            snacks->addChild(candy);
            food->addChild(fruits);
            food->addChild(snacks);

            ShopNode* games = new ShopNode("Games");
            ShopNode* pc = new ShopNode("PC");
            ShopNode* desktop = new ShopNode("Desktop");
            ShopNode* laptop = new ShopNode("Laptop");
            pc->addChild(desktop);
            pc->addChild(laptop);
            ShopNode* console = new ShopNode("Console");
            ShopNode* xbox = new ShopNode("Xbox");
            ShopNode* xbox360 = new ShopNode("Xbox 360");
            ShopNode* xboxOne = new ShopNode("Xbox One");
            xbox->addChild(xbox360);
            xbox->addChild(xboxOne);
            ShopNode* halo = new ShopNode("Halo");
            ShopNode* forza = new ShopNode("Forza");
            xboxOne->addChild(halo);
            xboxOne->addChild(forza);
            ShopNode* playstation = new ShopNode("PlayStation");
            ShopNode* ps4 = new ShopNode("PS4");
            ShopNode* ps5 = new ShopNode("PS5");
            playstation->addChild(ps4);
            playstation->addChild(ps5);
            ShopNode* spiderman = new ShopNode("Spider-Man: Miles Morales");
            ShopNode* ratchetClank = new ShopNode("Ratchet & Clank: Rift Apart");
            ps5->addChild(spiderman);
            ps5->addChild(ratchetClank);
            console->addChild(xbox);
            console->addChild(playstation);
            games->addChild(pc);
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
        std::cout << "You have chosen: " << selection << std::endl;
    }
};

#endif
