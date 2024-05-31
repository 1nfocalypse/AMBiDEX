#include "Simulation.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>


Simulation::Simulation() : numPlayers(3), strangerPaid(0) {}

void Simulation::run() {
	std::vector<bool> flipResults;
	std::vector<bool> announcements;
	bool evenOrOdd = numPlayers % 2; // true = odd, false = even
	int liar;
	std::mt19937 gen(time(0)); // seed the generator
	std::uniform_int_distribution<> distr(0, 1);
	std::uniform_int_distribution<> distrib(0, numPlayers - 1);
	// flip coin off unif distrib w/ Mersenne Twister (in practice, should be true random, psuedorandom used for toy)
	for (int i = 0; i < numPlayers; ++i) {
		flipResults.push_back(distr(gen));
	}
	// if player paying, determine liar
	if (!strangerPaid) {
		liar = distrib(gen);
	}
	// right hand player evaluates in a circular fashion, hence last index evaluates 0
	for (int i = 0; i < numPlayers; ++i) {
		int evaluator = (i + 1) % (numPlayers) ;
		bool sameOrDiff; // 1 is same, 0 is different
		if (flipResults[evaluator] == flipResults[i]) {
			sameOrDiff = 1;
		}
		else {
			sameOrDiff = 0;
		}
		if (!strangerPaid) {
			if (evaluator == liar) {
				sameOrDiff = !sameOrDiff;
			}
		}
		announcements.push_back(sameOrDiff);
	}
	int totalDiff = 0;
	for (int i = 0; i < announcements.size(); ++i) {
		if (announcements[i] == 0) {
			totalDiff++;
		}
	}
	if (totalDiff % 2 == 1) {
		std::cout << "A player paid.\n";
	}
	else {
		std::cout << "A stranger paid.\n";
	}
}

void Simulation::configure() {
	std::string numPlayersProxy;
	std::string payerProxy;
	int stoiFlag = 1;
	while (stoiFlag != 0) {
		tryblock:
		try {
			std::cout << "Please enter a number of players greater than or equal to 2." << std::endl;
			std::getline(std::cin, numPlayersProxy);
			while (std::stoi(numPlayersProxy) < 2) {
				std::cout << "Please enter a number of players greater than or equal to 2." << std::endl;
				std::getline(std::cin, numPlayersProxy);
			}
		}
		catch (const std::exception& e) {
			goto tryblock;
		}
		stoiFlag = 0;
	}
	numPlayers = std::stoi(numPlayersProxy);
	std::cout << "Is a stranger paying? 1 for yes, 0 for no." << std::endl;
	std::getline(std::cin, payerProxy);
	while (std::stoi(payerProxy) != 0 && std::stoi(payerProxy) != 1) {
		std::cout << "Is a stranger paying? 1 for yes, 0 for no." << std::endl;
		std::getline(std::cin, payerProxy);
	}
	strangerPaid = std::stoi(payerProxy);
	std::cout << "Configuration updated.\nCurrent configuration is printed below." << std::endl;
	printConfig();
}

void Simulation::printConfig() {
	std::cout << "Number of users: " << numPlayers << std::endl;
	if (strangerPaid) {
		std::cout << "Stranger paying." << std::endl;
	}
	else {
		std::cout << "Stranger not paying." << std::endl;
	}
	std::cout << "*******************************************" << std::endl;
}