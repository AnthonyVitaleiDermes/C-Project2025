#include <iostream>
#include <string>
#include "shop.h" 
#include "Money.h" 
#include "Game.h"



int main() // yur 5"3 asain girl abg >> 
{
    std::string userName;

    std::cout << "What is your name? ";
    std::getline(std::cin, userName);

    std::cout << "Hello, " << userName << "! Welcome!" << std::endl;

    Money userMoney;
    userMoney.setAmount(100.00f);
 
    Shop<int, float> shopCity;
    RPSGame game;
    while (true) {

        int action;

        std::cout << "Welcome To the online store and games\n";
        std::cout << "Press 1 for the Shop and 2 for the Minigame to earn money!\n";
    
        std::cin >> action;
        if (action == 0) {
            std::cout << "Thanks for playing! Bye Bye\n";
            break;
        }

        switch (action)
        {
        case 1:
            shopCity.displayShopMenu(userMoney);
            shopCity.interact(userMoney);
            break;
        case 2: {
            RPSGame game;
            std::string choice;
            std::cout << "Welcome To The Minigame! Earn or lose money by playing Rock-Paper-Scizzors.\n";

            while (true) {
                std::cout << "Enter rock,paper, or scizzors (or 'quit' to exit):";
                std::cin >> choice;

                if (choice == "quit") break;

                std::cout << game.playRound(choice) << std::endl;
                game.EarningsDisplayed();
            }
            std::cout << "Final money Amount: ";
            userMoney.setAmount(game.getEarnings()); // update's the user's money balance
            userMoney.displayMoney();
            //Minigame Method
            break;
        }
        default:
            std::cout << "Invalid Option\n";
            break;
        }

    }

    return 0;
}

