#pragma once
class Simulation
{
private:
	int numPlayers;
	bool strangerPaid;

public:

	// ctor
	// PRE: Simulation object declared
	// POST: Simulation object initialized
	// WARNINGS: None
	// STATUS: Completed, tested
	Simulation();

	// run()
	// PRE: Simulation object exists, is configured correctly
	// POST: Simulation object states if a stranger or player paid
	// WARNINGS: None
	// STATUS: Completed, tested
	void run();

	// configure()
	// PRE: Simulation object exists
	// POST: Simulation settings changed per user request
	// WARNINGS: None
	// STATUS: Completed, tested
	void configure();

	// printConfig()
	// PRE: Simulation object exists, is configured correctly
	// POST: Current settings outputted
	// WARNINGS: None
	// STATUS: Completed, tested
	void printConfig();
};

