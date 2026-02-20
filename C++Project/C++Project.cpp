#include <iostream>
#include <string>
#include "shop.h"
#include "Money.h"
#include "Game.h"
#include "Inventory.h" 

int main() 
{
    std::string userName;

    std::cout << "What is your name? ";
    std::getline(std::cin, userName);
    std::cout << "Hello, " << userName << "! Welcome!" << std::endl;

    Money userMoney;
    userMoney.setAmount(100.00f);  // Start with $100



    Shop<int, float> shopCity;
    RPSGame game;

    while (true) {
        int action;

        std::cout << "\nWelcome to the online store and games!\n";
        std::cout << "Press 1 for the Shop, 2 for the Minigame, 3 to view your purchase history, or 0 to exit: ";
        std::cin >> action;

        if (action == 0) {
            std::cout << "Thanks for playing! Bye Bye\n";
            break;
        }

        switch (action) {
        case 1:
            shopCity.displayShopMenu(userMoney);
            shopCity.interact(userMoney);
           
            break;

        case 2: {
            std::string choice;
            std::cout << "Welcome to the Minigame! Earn or lose money by playing Rock-Paper-Scissors.\n";

            while (true) {
                std::cout << "Enter rock, paper, or scissors (or 'quit' to exit): ";
                std::cin >> choice;

                if (choice == "quit") break;

                std::cout << game.playRound(choice) << std::endl;
                game.EarningsDisplayed();
            }

            std::cout << "Final money amount: ";
            userMoney.setAmount(game.getEarnings()); // update the user's money balance
            userMoney.displayMoney();
            break;
        }

        case 3: {
              shopCity.displayPurchaseHistory(); // this is a stack
              break;
        }


        default:
            std::cout << "Invalid option. Please choose 1, 2 or 0 to exit.\n"; 
            break;
        }
    }

    return 0;
}