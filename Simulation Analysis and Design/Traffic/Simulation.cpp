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
#include "Travel.h"
#include <iostream>

/**
 * [Simulation::Simulation Constructor that requires number of simulations to run]
 * @param _simulations [Integer: Number of times to run simulation]
 * @param _display     [Boolean: to display simulation information or not]
 */
Simulation::Simulation(int _simulations, bool _display)
{
        numOfSimulations = _simulations;
        display = _display;
        setupTraffic();
        setupTerrain();
        setupRoadConditions();
        runSimulation();
}

/**
 * [Simulation::Simulation Constructor for using default number of simulations]
 * @param _display [Boolean: to display simulation information or not]
 */
Simulation::Simulation(bool _display)
{
        numOfSimulations = 100;
        display = _display;
        setupTraffic();
        setupTerrain();
        setupRoadConditions();
        runSimulation();
}

/**
 * [Simulation::getNumOfSims Getter for number of times to run simulation]
 * @return [Integer: number of times to run simulation]
 */
int Simulation::getNumOfSims()
{
        return numOfSimulations;
}

/**
 * [Simulation::getAverage Getter for average time taken to reach destination from starting point]
 * @return [Average time taken to reach destination from starting point]
 */
double Simulation::getAverage()
{
        return averageTime;
}

/**
 * [Simulation::getStart Getter for starting point of journey]
 * @return [Integer: Starting position on the straight road.]
 */
int Simulation::getStart()
{
        return start;
}

/**
 * [Simulation::getEnd Getter for destination point of journey]
 * @return [Integer: Ending position on the straight road]
 */
int Simulation::getEnd()
{
        return end;
}

/**
 * [Simulation::getLights Getter for how many miles should be between each traffic light]
 * @return [Integer: Number of miles between each traffic light]
 */
int Simulation::getLights()
{
        return lights;
}

/**
 * [Simulation::getSpeed Getter for speed in mph]
 * @return [Integer: Speed limit for stretch of road]
 */
int Simulation::getSpeed()
{
        return speed;
}

/**
 * [Simulation::calcAverage Calculate the average time taken to reach destination
 * from starting point from all simulation results.]
 */
void Simulation::calcAverage()
{
        int total = 0;
        for(int i = 0; i < numOfSimulations; i++)
        {
                total += allResults.at(i);
        }

        averageTime = (total * 1.0)/numOfSimulations;
}

/**
 * [Simulation::runSimulation Run the given scenario the amount of times specified
 * by the user as the number of times to run the simulation. Each individual scenario
 * will begin at the specified starting point. At each movement, the 'driver' will decide
 * to move forward or backward. This will continue, adding time as appropriate, until the
 * destination is reached. The time taken for each individual scenario will be added
 * to a vector of results.]
 */
void Simulation::runSimulation()
{
        double timeInHours;
        for(int i = 0; i < numOfSimulations; i++)
        {
                Travel travel(red, start, end, speed, lights, display, condition);
                double currentTotalTime = travel.getTotalTime();
                timeInHours = (currentTotalTime/60)/60;
                if(display)
                {
                        std::cout<<"--------------------------------"<<std::endl;
                        std::cout<<i+1<<" : "<<timeInHours<<" hours."<<std::endl;
                        std::cout<<"--------------------------------"<<std::endl;
                }
                allResults.push_back(timeInHours);
        }

        calcAverage();
}

/**
 * [Simulation::setupTraffic Set up the traffic conditions for the stretch of road.
 * This includes determining if the user wants to enter their own values, or use default values.
 * The variables set here involve red light time and speed limit.]
 */
void Simulation::setupTraffic()
{
        int choice;
        std::cout<<"Choose an option for traffic conditions:"<<std::endl;
        std::cout<<"1. Enter values for light times and speed limit."<<std::endl;
        std::cout<<"2. Enter values for light times and use default speed limit."<<std::endl;
        std::cout<<"3. Enter speed limit and use default values for light times."<<std::endl;
        std::cout<<"4. Use default values for all variables."<<std::endl;
        std::cin>>choice;

        if(choice == 1) {
                std::cout << "Enter the red light time in seconds: "<<std::endl;
                std::cin >> red;
                std::cout<<"Enter speed limit: "<<std::endl;
                std::cin >>speed;

        }

        else if(choice == 2) {
                std::cout << "Enter the red light time in seconds: "<<std::endl;
                std::cin >> red;
                speed = 30;
        }

        else if(choice == 3)
        {
                std::cout<<"Enter the speed limit: "<<std::endl;
                std::cin>>speed;
                red = 90;
        }
        else if(choice == 4)
        {
                std::cout<<"Using default values."<<std::endl;
                red = 90;

                speed = 30;
        }
        else
        {
                std::cout << "Invalid input."<<std::endl;
                setupTraffic();
        }

}

/**
 * [Simulation::setupTerrain Set up the terrain values. Here the user can customize
 * starting point, ending point, and the number of miles between traffic lights.
 * They may also choose to use the default values for each.]
 */
void Simulation::setupTerrain()
{
        int choice;
        std::cout<<"Choose terrain option: "<<std::endl;
        std::cout<<"1. Enter a starting point, ending point, and number of traffic lights per mile."<<std::endl;
        std::cout<<"2. Enter a starting point and ending point and use a default number of traffic lights."<<std::endl;
        std::cout<<"3. Enter a number of traffic lights per mile and use default starting and ending points."<<std::endl;
        std::cout<<"4. Use default values for all variables"<<std::endl;
        std::cin >> choice;

        if(choice == 1)
        {
                std::cout <<"Enter starting point: "<<std::endl;
                std::cin >> start;

                std::cout <<"Enter ending point: "<<std::endl;
                std::cin >> end;

                std::cout << "Enter the number of miles between traffic lights: "<<std ::endl;
                std::cin >> lights;

        }

        else if(choice == 2)
        {
                std::cout <<"Enter starting point: "<<std::endl;
                std::cin >> start;

                std::cout <<"Enter ending point: "<<std::endl;
                std::cin >> end;
                lights = 3;
        }

        else if(choice == 3)
        {
                start = 4;
                end = 12;
                std::cout<<"Enter the number of miles between traffic lights: "<<std::endl;
                std::cin >> lights;
        }
        else if(choice == 4)
        {
                std::cout<<"Using default values."<<std::endl;

                start = 4;
                end = 12;
                lights = 3;
        }

        else
        {
                std::cout<<"Invalid input."<<std::endl;
                setupTerrain();
        }
}

void Simulation::setupRoadConditions()
{
  int choice;
  std::cout<<"Choose road condition option: "<<std::endl;
  std::cout<<"1. Standard road conditions."<<std::endl;
  std::cout<<"2. Inclement weather conditions."<<std::endl;
  std::cout<<"3. Accident on road."<<std::endl;
  std::cout<<"4. Heavy traffic."<<std::endl;
  std::cin >> choice;

  if(choice > 4 || choice < 1)
  {
    std::cout<<"Invalid input."<<std::endl;
    setupRoadConditions();
  }

  condition = choice;

}
