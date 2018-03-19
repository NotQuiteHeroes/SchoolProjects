# Return on Investment Monte Carlo Simulation

This program calculates return on investment for a given number of years, initial investment, desired return, and standard deviation. 

The return percentage for each year is determined by an implementation of Excel's normInv function, which in turn relies on a random number generation. The normInv function was translated to C++ from [kmpm's Javascript version](https://gist.github.com/kmpm/1211922/6b7fcd0155b23c3dc71e6f4969f2c48785371292). 

A single simulation run calculates the individual year's results, then saves the final total. Once all simulations have been run, the final totals are added up and used to determine the mean and median of all the simulation runs. 

The number of years, initial investment, desired return, standard deviation, and number of simulations to run can all be set by the user, or the user can choose to use the default values.

#### Default Values of Program:
+ Number of Years       : 7
+ Initial Investment    : $150,000
+ Number of Simulations : 100
+ Desired Return        : 10%
+ Standard Deviation    : .15

## Files:
+ Validation.h/.cpp : The Validation class is implemented when the user decides to enter their own numbers for the simulation. It ensures the number of years is greater than 0, the number of simulations is greater than 0, the desired return is in a decimal form between 0 and 1, the standard deviation is in decimal form between 0 and 1, and that the initial investment is greater than 0.
+ Calculator.h/.cpp : Acts as a more complicated back end to the ROI front end. It performs each simulation run's calculations, such as determining individual year's return, as well as totaling each simulation's final total. It is also where the main simulation loop is run.
+ ROI.h/.cpp : Acts as a more simplified front-end to the calculator back-end. This is where all simulation variables are stored and passed to the Calculator. It also displays the final results of all simulation runs. 
+ ROITest.cpp : This is the testfile for the program. It currently has creation of the ROI objects hardcoded for testing purposes. 

## Compilation:
g++ Calculator.cpp Validation.cpp ROI.cpp ROITest.cpp

## Execution:
a.exe

#### Using default values for simulation variables:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationROICalculator.JPG "Default values")

#### Using non-default values for simulation variables:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationROICalculator2.JPG "Non-default values")
