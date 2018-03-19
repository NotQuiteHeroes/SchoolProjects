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
#ifndef __TRAVEL__
#define __TRAVEL__

class Travel
{
private:
double totalTime;
double turnAroundTime;
int start, end;
int red;
int speed;
int lights;
bool display;
int accidentLocation;
int condition;

public:
Travel(int _red, int _start, int _end, int _speed, int _lights, bool _display, int _condition);
double getTotalTime();
void randomWalk();

int determineLight();
int determineMove();
void determineConditionEffects();

int getRandomInt();
double getRandom();
};

#endif
