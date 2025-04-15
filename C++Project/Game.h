#ifndef RPS_GAME_H
#define RPS_GAME_H 

#include <iostream>
#include <string>
#include "Money.h"
// Rock,Paper,Sizzors
class RPSGame {
public:
	RPSGame();
	std::string playRound(std::string playerchoice);
	void EraningsDisplayed() const;
	float getEarnings() const;
private:
	Money playerMoney;
	std::string getComputerChoice();
	int determineTheWinner(std::string playerchoice, std::string computerChoice);
	
};
#endif  //RPS_GAME_H


