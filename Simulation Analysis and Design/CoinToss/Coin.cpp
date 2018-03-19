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

/**
 * [Coin toss - randomly picks 1 or 2 representing heads or tails]
 * @return [result of coin toss - 1 = heads, 2 = tails]
 */
int Coin::headsOrTails()
{
        return(std::rand() % 2 + 1);
}

/**
 * [Displays results of coin toss in unmuted mode]
 * @param p_toss [result of coin toss - 1 = heads, 2 = tails]
 */
void Coin::displayResults(int p_toss)
{
        std::string toss;
        if(p_toss == 1)
        {
                toss = "Heads";
        }
        else
        {
                toss = "Tails";
        }

        std::cout<<"Toss..."<<toss<<"!"<<std::endl;
}

/**
 * [Coin constructor]
 * @param p_numOfTosses    [Number of simulations to run]
 * @param p_expectedReturn [Expected return]
 * @param p_minReturn      [Minimum expected return]
 * @param mode             [(0)Muted or (1)Unmuted]
 */
Coin::Coin(int p_numOfTosses, int p_expectedReturn, int p_minReturn, int mode)
{
        srand(time(NULL));

        heads = 0;
        tails = 0;
        numOfTosses = p_numOfTosses;
        expectedReturn = p_expectedReturn;
        minReturn = p_minReturn;

        if(mode == 0)
        {
                muted = true;
        }
        else
        {
                muted = false;
        }

        runSimulation();
}

/**
 * [Run Monte Carlo Simulation]
 */
void Coin::runSimulation()
{
        int count = 0, toss = 0, difference = 0;

        //loop for simulations
        for(int i = 0; i < numOfTosses; i++)
        {
                heads = 0;
                tails = 0;

                //loop for individual simulation
                for(int j = 0; j < (expectedReturn+minReturn); j++)
                {
                        toss = headsOrTails();
                        if(toss == 1)
                        {
                                heads++;
                        }
                        else
                        {
                                tails++;
                        }
                        if(!muted)
                        {
                                displayResults(toss);
                        }
                } // end individual simulation

                difference = std::abs(heads - tails);
                if(difference >= std::abs(minReturn - expectedReturn))
                {
                        count++;
                }

        } //end all simulations
        finalResults(count);
}

/**
 * [finalResults displays final information of Monte Carlo simulation
 * including P-Value]
 * @param count [Accumulation of difference greater than expected occurring]
 */
void Coin::finalResults(int count)
{
        std::cout<<"--------------------------------"<<std::endl;
        std::cout<<"-----Simulation Information-----"<<std::endl;
        std::cout<<"--------------------------------"<<std::endl;
        std::cout<<"Number of Simulations: "<<numOfTosses<<std::endl;
        std::cout<<"Expected Return: "<<expectedReturn<<std::endl;
        std::cout<<"Minimum Return: "<<minReturn<<std::endl;
        std::cout<<"---------------------------------"<<std::endl;
        std::cout<<"-------Simulation Results-------"<<std::endl;
        std::cout<<"---------------------------------"<<std::endl;
        std::cout<<"P-Value: "<<static_cast<double>(count)/numOfTosses<<std::endl;
        std::cout<<"--------------------------------"<<std::endl;

}
