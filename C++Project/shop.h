#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include "Money.h"

class Shop  
{
public:
    void displayShopMenu(Money& userMoney) {
        std::cout << "Welcome to the shop! Your current balance: $" << userMoney.getAmount() << std::endl;
    }
};

#endif