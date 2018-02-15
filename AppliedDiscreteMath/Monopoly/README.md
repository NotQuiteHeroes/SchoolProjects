# Monopoly

Program that implements a finite state machine to illustrate a single player's turn in monopoly. 

It begins by rolling the dice (using a random number generator). 
If the two dice don't match, the program will display the number of spaces the player moves, and end the program
(as this would be the end of the player's turn.) If, however, the player rolls doubles (the two dice match) then they get to roll
again. If, once again, the player doesn't roll doubles, then they will move the number of spaces, and the program will end. If the player
rolls doubles again, then the player will move on to roll again. Again, if the player doesn't roll doubles, the player will move
the required spaces, and the turn (program) will end. If the player rolls a double for the third time, though, they will be sent to
jail and their turn will end.

The state transitions can be described as thus:

Initial state: first roll
if first roll is doubles, go to first double roll
else go to exit state.

If first double roll is doubles, go to second double roll
else go to exit state.

If second double roll is doubles, go to jail
else go to exit state

If in jail, go to exit state.

Exit state: end turn.

## Input
None - no interaction by the user is required.

## Output
x

y

Moving x+y spaces.

Next State transition.

Where x is the first die roll result, y is the second die roll result, and next state transition is either end turn, first doubles, 
second doubles, or go to jail.

## Files:
+ Monopoly.cpp : entry point for the program. Creates a player object and runs loop for FSM until end turn state is reached.
+ Player.h/.cpp : Player object that holds it's FSM and a function to update the current state. Initializes new Player with FSM set to 
entry state
+ StateMachine.h/.cpp : Holds functionality for the FSM, such as setting the owner and the owner's current state, retrieving the
current state, updating, and changing states.
+ States.h/.cpp : Holds individual state information, as well as each states entry, update, and exit functionality.

## Compilation:
g++ *.cpp

## Execution:
a.exe

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathMonopoly.JPG "Single player's turn in monopoly")


