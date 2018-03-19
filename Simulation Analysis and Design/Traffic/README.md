# Traffic Flow Simulation

This is the course project for Simulation Analysis and Design. It is a basic simulation to determine the time it takes to reach point B from point A, implementing a random walk solution.

It emulates a single stretch of road as a number line, with one movement forward or backward equaling one mile. At x amount of miles, the driver will encounter a traffic light that has a equal chance of being red as it does being green.

The 'driver' at each mile has the same odds of moving forward as moving backward. If the drive moves backward, they must loop around the block to meet back up with the main road and continue on, which adds more time to the trip.

Moving forward one mile adds an amount of time to the trip, as does encountering a red light. 

The total time taken to reach point B from point A is saved after each individual simulation run, then added together after all simulations have been run to be used to determine the average time taken. 

The simulation variables are fully customizable, if the user so chooses, or default values are provided otherwise. The modifiable variables are:
+ Number of simulations
+ Traffic light timing
+ Speed limit
+ Starting and Ending points
+ Number of miles between traffic lights
+ Road conditions (such as inclement weather, accident, traffic, etc.)

## Files:
+ Simulation.h/.cpp : Sets up the variables listed above and implements the Travel class to perform the actual simulation run. It calculates the average after all simulations have been run. 
+ Travel.h/.cpp : This class handles an individual simulation run. This is also where the random walk solution is implemented. This class determines if the driver will move forward or backward, and if the traffic light encountered will be red or green. It adds time as necessary. 
+ trafficMain.cpp : This is the testfile for the program. It asks how many simulations to run, and if the user would like to see the output of the movements of the driver. It then launches the simulation and displays the final results at the end.

## Compilation:
g++ Simulation.cpp Travel.cpp trafficMain.cpp

## Execution:
a.exe

## Usage:

### Without road conditions added:
#### Using default variables and no display information
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficNoDisplay.JPG "Default - no display")

#### Using default variables with display information
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficWithDisplay.JPG "Default - with display")

#### Using non-default variables and no display information
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficNondefault.JPG "Nondefault - no display")

### With road conditions added:

#### Standard road conditions
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficStandard.JPG "Standard road conditions")

#### Heavy Traffic conditions
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficHeavyTraffic.JPG "Heavy traffic road conditions")

#### Accident on road conditions
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationTrafficAccident.JPG "Accident conditions")
