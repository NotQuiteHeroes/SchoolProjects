# Turing Machine

Illustrates a Turing Machine using a tape with given input and checks if the input meets the requirements of the hardcoded
grammar of a^n b^m c^n. 

This program uses a finite state machine to simulate the classic Turing Machine. The involved states are FirstState, FindA, FindB, FindC, 
EvaluateTape, RejectTape, and AcceptTape. 

The FirstState gets the string of characters from the user to check against the given grammar. It then performs an intial check of
the string. If the first character is not an a, there are less than four characters, or less than at least one of each required
character (a, b, c) then we can reject it immediately without further checks. 

If the string passes the initial checks, then the finite state machine changes to the FindA state, which finds the next 'a' character
and changes it to 'A' to show it has been evaluated. This state will then get the count of a and c characters left. If there are none, then
it will move to the evaluation state. If there are more remaining, then it will move to the FindB state. This state will act identically
to the FindA state, except looking for 'b' characters. It will then get a count of remaining c characters, and if there are none it will
move on to Evaluate, otherwise it will move on to FindC. FindC will in turn act as the above FindA and FindB, except it will check if
there are remaining 'a' characters left, if not move to Evaluate, if so loop back around to FindA. 

The loop of FindA, FindB, FindC will continue until all character's have been evaluated in the form of the given grammar. It will then reach
the EvaluateTape state. This state gets the count of all characters ('a' + 'A', 'b' + 'B', 'c' + 'C'). If the count of 'a' characters does
not equal the count of 'c' characters, then it will be rejected. If the 'b' count is the same as either the 'a' or 'c' count, then it will
rejected. 

If the tape hasn't been rejected yet, then it will check to make sure the format follows abc, with no a's happening after b or c, no b's 
occuring after c, etc. If this check doesn't reject the tape, then it will have met the requirements based on the grammar, and the state
will change to AcceptTape. 

The Turing Machine acts as the owner of the state machine, and holds methods to act upon the tape, such as updating the tape
when changes are made, and updating the status of the tape (evaluation status).

## Input:
Characters to check against the grammar, followed by an 'x' to indicate end of input. Each character is entered one at a time, pressing
enter after each.

Example:

a

a

b

c

c

x

## Output:
Tape Accepted or Tape Rejected.

## Files:
+ Turing.cpp : The entry point for the program. This creates a TM object and sets its status to 0 to indicate it still needs to be
evaluated. It then runs in a loop while the TM's status is 0.
+ TM.h/.cpp : Holds the Turing Machine class that acts as the owner of the State Machine, as well as contains methods for acting upon 
the tape.
+ StateMachine.h/.cpp : State Machine class that holds methods to detail calls to update or change state.
+ States.h/.cpp : States for the State Machine to shuffle through. These include FirstState, FindA, FindB, FindC, EvaluateTape, Accept,
and Reject

## Compilation:
g++ *.cpp

## Execution:
a.exe

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathTuring.JPG "Turing Machine Evaluation")

