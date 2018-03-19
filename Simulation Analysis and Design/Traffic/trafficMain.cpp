/*
   Paige Eckstein
   Simulation Analysis and Design
   3/5/2018

   Traffic Flow Simulation
   This is a basic simulation to determine the time it takes to reach point A from point B.
   It implements a random walk solution.
   It emulates a single stretch of 'road' as a number line, with one movement
   forward or backward equaling one mile.
   The 'driver' at each mile has the same odds of moving forward as moving backward.
   If the driver moves backward, they must loop around the block to meet back up with the main road
   and continue on. This adds more time.
   Moving forward one mile adds more time, as does stopping at a red light.

   The simulation and its variables are fully customizable.
   The user can set:
   -number of simulations to run
   -whether or not to display traffic movements and traffic lights encountered
   -the time it takes at a red light
   -how far apart traffic lights occur
   -the speed limit
   -the starting and ending locations
   Or they can use default values for everything listed above.

   Compilation:
   g++ Simulation.cpp Travel.cpp trafficMain.cpp

   Execution:
   a.exe

   Test file:
   trafficMain.cpp

   No requirements
 */
#include "Simulation.h"
#include <iostream>

using namespace std;

void displayResults(Simulation sim);

int main()
{
        int choice;
        cout<<"================================================="<<endl;
        cout<<"============ Traffic Flow Simulation ============"<<endl;
        cout<<"================================================="<<endl;
        cout<<"Choose a simulation option: "<<endl;
        cout << "1. Enter number of simulations to run."<<endl;
        cout << "2. Use default number of simulations."<<endl;
        cin >> choice;

        if(choice == 1)
        {
                int numOfSims;
                string answer;
                cout << "Enter number of simulations to run: "<<endl;
                cin >> numOfSims;
                cout << "Would you like to see traffic movements displayed? (yes/no)"<<endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes" || answer == "Y" || answer == "y")
                {
                        Simulation sim(numOfSims, true);
                        displayResults(sim);
                }
                else
                {
                        Simulation sim(numOfSims, false);
                        displayResults(sim);
                }
        }
        else
        {
                string answer;
                cout << "Would you like to see traffic movements displayed? (yes/no)"<<endl;
                cin >> answer;
                if(answer == "yes" || answer == "Yes" || answer == "Y" || answer == "y")
                {
                        Simulation sim(true);
                        displayResults(sim);
                }
                else
                {
                        Simulation sim(false);
                        displayResults(sim);
                }
        }

        return 0;
}

void displayResults(Simulation sim)
{
        cout<<"================================================="<<endl;
        cout<<"===================== Results ==================="<<endl;
        cout<<"================================================="<<endl;
        cout<<"Number of simulations run: "<< sim.getNumOfSims()<<endl;
        cout<<"Starting Point: "<<sim.getStart()<<endl;
        cout<<"Ending Point: "<<sim.getEnd()<<endl;
        cout<<"Speed: "<<sim.getSpeed()<<endl;
        cout<<"Traffic lights every "<<sim.getLights()<<" miles."<<endl;
        double averageTime = sim.getAverage();
        if(averageTime < 1)
        {
                cout<<"Average time to travel: "<<averageTime*60<<" minutes."<<endl;
        }
        else
        {
                cout<<"Average time to travel: "<<(sim.getAverage())<<" hours."<<endl;
        }
        cout<<"================================================="<<endl;
}
