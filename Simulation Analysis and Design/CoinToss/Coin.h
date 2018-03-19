/**
 * Paige Eckstein
 * Simulation Analysis and Design
 * 01/14/18
 *
 * Coin class creates an object to run a
 * Monte Carlo simulation of tossing a coin.
 *
 * Given the number of simulations to run,
 * the expected return, and the minimum expected
 * return, each coin object will run the simulation
 * and display the P-Value for the given input.
 *
 * Has two modes, muted and unmuted.
 * Unmuted will display results of each coin toss.
 * Unmuted simply displays the final results.
 *
 * No dependencies.
 * Tested with monteCarloCoinTossTest.cpp
 *
 * Reference:
 * Saha-Mandal et.al, 2013
 * Retrieved from:
 * http://bpg.utoledo.edu/~afedorov/lab/DOWNLOADS_WEB/MonteCarlo.txt
 */
#ifndef __COIN__
#define __COIN__

#include <ctime>
#include <cstdlib>
#include <iostream>

class Coin
{
private:
int heads, tails, mode;
int numOfTosses, expectedReturn, minReturn;
bool muted;

int headsOrTails();
void displayResults(int p_toss);

void runSimulation();
void finalResults(int count);

public:
Coin(int numOfTosses, int expectedReturn, int minReturn, int mode);

};

#endif //__COIN__
