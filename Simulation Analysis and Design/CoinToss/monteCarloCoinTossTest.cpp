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
#include "Coin.h"

using namespace std;

int main()
{
        int numOfTosses, expectedReturn, minReturn;
        char mute;

        cout<<"Enter number of simulations: "<<endl;
        cin>>numOfTosses;

        cout<<"Enter expected return: "<<endl;
        cin>>expectedReturn;

        cout<<"Enter minimum return: "<<endl;
        cin>>minReturn;

        cout<<"Would you like to see the output of the coin toss? (y/n)"<<endl;
        cin>>mute;

        if(tolower(mute) == 'y')
        {
                Coin coin(numOfTosses, expectedReturn, minReturn, 1);
        }
        else
        {
                Coin coin(numOfTosses, expectedReturn, minReturn, 0);
        }
        return 0;
}
