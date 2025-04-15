#pragma once    
#include <iostream>
#include <string>
#include "Money.h"
// Rock,Paper,Sizzors
class RPSGame {
public:
	std::string playRound(std::string playerchoice);
	int getyourEarnings() const;
private:
	int earnings;
	std::string getComputerChoice();
	int determineTheWinner(std::string playerchoice, std::string computerChoice);
	
};


