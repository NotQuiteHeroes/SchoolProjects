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
#include "Travel.h"
#include <iostream>
#include <random>

/**
 * [Travel::Travel Travel constructor. Requires all information for fields]
 * @param _red     [Integer: time it takes for a red light]
 * @param _start   [Integer: starting location on the straight road. Same idea as a number line.]
 * @param _end     [Integer: ending location on a straight road. Same idea as a number line.]
 * @param _speed   [Integer: speed limit]
 * @param _lights  [Integer: number of miles between each traffic light]
 * @param _display [Boolean: to display simulation information or not]
 */
Travel::Travel(int _red, int _start, int _end, int _speed, int _lights, bool _display, int _condition)
{
        red = _red;
        start = _start;
        end = _end;
        speed = _speed;
        lights = _lights;
        turnAroundTime = 12 + (speed/3600);
        display = _display;
        condition = _condition;
        accidentLocation = -5;
        determineConditionEffects();
        randomWalk();
}

void Travel::determineConditionEffects()
{
  switch(condition)
  {
    //1 = standard conditions, no change
    case 1:
      break;
    //2 = inclement weather, slow down speed by 5
    case 2:
    {
      speed -= 5;
      break;
    }
    //3 = accident on road
    case 3:
    {
      accidentLocation = getRandomInt();
      break;
    }
    //4 = heavy traffic
    case 4:
    {
      speed -= 10;
      break;
    }
  }
}
/**
 * [Travel::randomWalk Simple random walk implementation. The straight road is the same as
 * a number line. While the current position is not the destination, the 'driver' will move
 * forward or backward one pace (This is randomly chosen with equal probability of occurrence)
 * Moving either direction will add time, but moving backward will add more time than moving forward,
 * as moving backward involves having to 'go around the block' to get back onto the stretch
 * of main road. The driver has a random chance of encountering a red light or a green light.
 * Red lights will add time.]
 */
void Travel::randomWalk()
{
        int currentTime = 0;

        //start at point A
        int currentPosition = start;
        //number of miles between traffic lights
        int movesUntilLight = lights;

        //while current position is not point B
        while(currentPosition != end)
        {
                //if a traffic light occurs
                if(movesUntilLight == 0)
                {
                        //determine if the light is red or green and add the appropriate time
                        //note: green adds 0
                        currentTime+=determineLight();
                        //reset counter until next light
                        movesUntilLight = lights;
                }

                //get 'driver's' directional movement (forward or backward)
                int movement = determineMove();

                //if 'driver' moves backward
                if(movement == -1)
                {
                        //setting 'road block' at 0. If current position is at 0 or less,
                        //then we can only move forward, so move forward instead
                        if(currentPosition <= 0)
                        {
                                movement = 1;
                        }
                        else{
                                //add time to turn around to get back on main road
                                currentTime+=turnAroundTime;
                        }
                }

                //time to move forward = speed limit / seconds in an hour
                double timeToMove = ((speed) / 3600);
                currentTime+=timeToMove;

                //move 'driver' forward one mile
                currentPosition+=movement;

                //if current position is where accident occurs, add time to
                //maneuver around accident
                if(currentPosition == accidentLocation)
                {
                  currentTime+=turnAroundTime;
                }

                if(display)
                {
                        std::cout<<"Current position: "<<currentPosition<<std::endl;
                }
                //count movement as one toward next traffic light encounter
                movesUntilLight--;
        }

        //current time kept running track of time taken to move from point a to point b,
        //thus it is our total time for the single scenario
        totalTime = currentTime;
}

/**
 * [Travel::determineMove Randomly pick a number between 0 and 1. If the number is greater
 * than .5, then the 'driver' moves forward. Otherwise, the drive moves backward]
 * @return [Integer: 1 to move forward, -1 to move backward]
 */
int Travel::determineMove()
{
        double move = getRandom();

        if(move > .5)
        {
                return 1;
        }
        else
        {
                return -1;
        }
}

/**
 * [Travel::determineLight Randomly pick a number between 0 and 1. If the number is greater
 * than .5, then the traffic light encountered by the 'driver' was green. Otherwise, the
 * traffic light was red.]
 * @return [Integer: The number of seconds to stop at the randomly chosen traffic light.]
 */
int Travel::determineLight()
{
        double type = getRandom();
        if(type > .5)
        {
                if(display)
                {
                        std::cout<<"At a green light."<<std::endl;
                }
                return 0;
        }
        else
        {
                if(display)
                {
                        std::cout<<"At a red light."<<std::endl;
                }
                return red;
        }
}

/**
 * [Travel::getRandom Return a random decimal between 0 and 1. Used to decide of the 'driver'
 * moves forward or backward, as well as what light the traffic lights encountered will be.]
 * @return [Double: A random decimal number between 0 and 1.]
 */
double Travel::getRandom()
{
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double> distribution(0, 1);
        return (distribution(generator));
}

int Travel::getRandomInt()
{
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(0, end);
  return (distribution(generator));
}

/**
 * [Travel::getTotalTime Getter for total time taken to reach point B from point A]
 * @return [Double: Total amount of time in seconds it took for the 'driver' to reach
 * point B from point A.]
 */
double Travel::getTotalTime()
{
        return totalTime;
}
