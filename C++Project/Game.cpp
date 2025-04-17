#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

RPSGame::RPSGame() : playerMoney(0.0) {
    std::srand(std::time(nullptr));
}

std::string RPSGame::getLanasChoice() {
    int choice = std::rand() % 3;
    switch (choice) {
    case 0: return "rock";
    case 1: return "paper";
    case 2: return "scizzors";
    }
    return "paper";
}

int RPSGame::determineTheWinner(const std::string& playerChoice, const std::string& lanasChoice) {
    if (playerChoice == lanasChoice)
        return 0;
    if ((playerChoice == "rock" && lanasChoice == "scizzors") ||
        (playerChoice == "paper" && lanasChoice == "rock") ||
        (playerChoice == "scizzors" && lanasChoice == "paper"))
        return 1;
    return -1;
}

std::string RPSGame::playRound(const std::string& playersChoice) {
    std::string lanasChoice = getLanasChoice();
    int result = determineTheWinner(playersChoice, lanasChoice);
    if (result == 1) {
        playerMoney.setAmount(playerMoney.getAmount() + 20.0);
        return "You win! Lana chose " + lanasChoice + ". You have earned $20.";
    }
    else if (result == -1) {
        playerMoney.setAmount(playerMoney.getAmount() - 10.0);
        return "You lose! Lana chose " + lanasChoice + ". You lost $10.";
    }
    else {
        return "It's a draw! Lana chose " + lanasChoice + ". No money was won or lost.";
    }
}

void RPSGame::EarningsDisplayed() const {
    std::cout << "Current money: ";
    playerMoney.displayMoney();
}

float RPSGame::getEarnings() const {
    return playerMoney.getAmount();
}