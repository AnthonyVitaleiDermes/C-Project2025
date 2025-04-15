#include "Game.h" // uses the game.h Headerfile
#include <iostream>  
#include <cstdlib>
#include <ctime>  //provides a function for handling time

//srand a is a function that seeds the random number generator
RPSGame::RPSGame() : playerMoney(0.0) {
	std::srand(std::time(nullptr)); //Seed for randomess 
}
//this basically randomly generates the computers choice
std::string RPSGame::getLanasChoice() {
	int choice = std::rand() % 3;
	switch (choice) {
		case0: return "rock";
		case1: return "paper";
		case2: return "scizzors";
	}
	return "rock";
}
//makes sure it determines who wins by seing what beats what the,rock,paper,scizzors beats 
int RPSGame::determineTheWinner(std::string playerChoice, std::string LanasChoice) {
	if (playerChoice == LanasChoice) return 0;
	if ((playerChoice == "rock" && LanasChoice == "scizzors") ||
		(playerChoice == "paper" &&LanasChoice == "rock") ||
		(playerChoice == "scizzors" && LanasChoice == "paper")) {
			return 1;
	}
	return -1;
}
std::string RPSGame::playRound(std::string playersChoice) {
	std::string LanasChoice = getLanasChoice();
	int result = determineTheWinner(playersChoice, LanasChoice);

	//functionality for player earning the money
	if (result == 1) {
		playerMoney.setAmount(playerMoney.getAmount() + 20.0); //player earns money
		return "you win! Lana chose" + LanasChoice + ". You have earned $20.";
	}
	//functionality for losing money vs the computer called(Lana)
	else if (result == -1) {
		playerMoney.setAmount(playerMoney.getAmount() - 10.0); // player loses Money
		return "You lose! Lana chose " + LanasChoice + ". You lost $10";
	} else{
		return "it's a draw! Noth chose" + LanasChoice + ". No money was won or lost.";
	}
}
//displays you current earnings earned by playing rock,paper,scizzors
void RPSGame::EarningsDisplayed() const {
	std::cout << "Current money: ";
	playerMoney.displayMoney();
}
//gets the earnings and returns the players amount
float RPSGame::getEarnings() const {
	return playerMoney.getAmount();
}

