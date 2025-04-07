#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include "Money.h"

class Shop  
{
public:
    void displayShopMenu(Money& userMoney) {
        std::cout << "Welcome to the shop! Your current balance: $" << userMoney.getAmount() << std::endl;

        std::cout << "Which section would you like to go to?" << std::endl;
        std::cout << "1. Clothes" << std::endl;
        std::cout << "2. Food" << std::endl;
        std::cout << "3. Games" << std::endl;
        std::cout << "Enter the number of your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "You selected the Clothes section." << std::endl;
            // call clothes section method
            break;
        case 2:
            std::cout << "You selected the Food section." << std::endl;
            // call food section method
            break;
        case 3:
            std::cout << "You selected the Games section." << std::endl;
            // game section method
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
    
};

#endif