# Monte Carlo Coin Toss Simulation

This program acts as a Monte Carlo Simulation of tossing a coin. The user enters the number of simulations to run, as well as the expected number of heads and expected number of tails.

The program uses random number generation to determine if a coin toss is heads or tails. Each simulation loops a total of expectedHeads + expectedTails times and keeps track of the number of heads and tails actually experienced. 

At the end of each individual simulation run, the absolute value of the difference between experienced heads and tails. If this difference is greater than the absolute value of the difference between expected heads and tails, then it adds one to the counter that keeps track of differences greater than expected.

Once every single simulation has been run, the program determines the P-value by dividing the count of differences greater than expected by the total number of simulations ran, and displays the final results.

## Compilation:
g++ Coin.cpp monteCarloCoinTossTest.cpp

## Execution:
a.exe

## Output:

This program has two modes, muted and unmuted, that the user can pick at the beginning of the simulation. Unmuted will display the results of each individual coin toss, whereas muted will only show the end results.

### Unmuted:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationCoinUnmuted.png "Unmuted coin toss run")

### Muted:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/simulationCoinMuted.png "Muted coin toss run")
