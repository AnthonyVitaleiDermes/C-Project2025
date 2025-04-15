#include "Game.h" // uses the game Headerfile
#include <iostream>  
#include <cstdlib>
#include <ctime>  //provides a function for handling time

//srand a is a function that seeds the random number generator
RPSGame::RPSGame() : playerMoney(0.0) {
	std::srand(std::time(nullptr)); //Seed for randomess 
}
//this basically randomly generates the computers choice
std::string RPSGame::getComputersChoice() {
	int choice = std::rand() % 3;
	switch (choice) {
		case0: return "rock";
		case1: return "paper";
		case2: return "scizzors";
	}
	return "rock";
}
//makes sure it determines who wins by seing what beats what the,rock,paper,scizzors beats 
int RPSGame::determineTheWinner(std::string playerChoice, std::string computersChoice) {
	if (playerChoice == computersChoice) return 0;
	if ((playerChoice == "rock" && computersChoice == "scizzors") ||
		(playerChoice == "paper" && computersChoice == "rock") ||
		(playerChoice == "scizzors" && computersChoice == "paper")) {
			return 1;
	}
	return -1;
}

