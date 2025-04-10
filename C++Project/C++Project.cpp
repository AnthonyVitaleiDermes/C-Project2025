#include <iostream>
#include <string>
#include "shop.h" 
#include "Money.h" 



int main() // yur 5"3 asain girl abg >> 
{
    std::string userName;

    std::cout << "What is your name? ";
    std::getline(std::cin, userName);

    std::cout << "Hello, " << userName << "! Welcome!" << std::endl;

    Money userMoney(100.0f); 
 
    int action;

    std::cout << "Welcome To the online store and games\n";
    std::cout << "Press 1 for the Shop and 2 for the Minigame to earn money!\n";

    std::cin >> action;


    switch (action)
    {
    case 1:
        Shop shopCity;

        shopCity.displayShopMenu(userMoney);
       

      
        //Shop Method //yo lowkey the way shop is spelled looks weird idk how to explain it
        break;
    case 2:
        std::cout << "Welcome To The Minigame!\n";
        //Minigame Method
        break;
    default:
        std::cout << "Invalid Option\n";
        break;
    }

    return 0;
}

