#ifndef GAME_H
#define GAME_H

#include <string>
#include "Money.h"

class RPSGame {
private:
    Money playerMoney;
public:
    RPSGame();
    std::string getLanasChoice();
    int determineTheWinner(const std::string& playerChoice, const std::string& lanasChoice);
    std::string playRound(const std::string& playersChoice);
    void EarningsDisplayed() const;
    float getEarnings() const;
};

#endif
