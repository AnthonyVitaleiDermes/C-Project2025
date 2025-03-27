#include <iostream>
#include <string>


int main() 
{
    int action;

    std::cout << "Welcome To the online store and games\n";
    std::cout << "Press 1 for the Shop and 2 for the Minigame to earn money!\n";

    std::cin >> action;


    switch (action)
    {
    case 1:
        std::cout << "Welcome To The Shop!\n";
        //Shop Method
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

