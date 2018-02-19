# Applied Discrete Mathematics

Collection of assignments from Applied Discrete Mathematics class. The focus of this class was implementing mathematical algorithms, such 
as RSA and Deferred Acceptance, as well as implementing finite state machines.

## Dijkstras
Given Graph information on all vertices and their accompanying edges, this program will implement Dijkstra's algorithm to find
the shortest path between the specified vertices. The vertices, edges, and start/end point are hardcoded for testing purposes, and can
be changed in the main function of the program. 

### Compilation:
*Note this will work for python2.7 and python3.x

python dijkstras.py

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathDijkstras.JPG "Dijkstra for path")

## Hanoi
Shows number of moves for classic Tower of Hanoi puzzle. This program gets the number of disks from the user and displays the moves of
each disk, before showing the total number of moves to solve the puzzle. 

### Compilation:
g++ hanoi.cpp

### Execution:
a.exe

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathHanoi.JPG "Dijkstra")

## Poker
Simulates a simplified two-player version of Texas Hold'em at the end of the round. It will calculate, given the player's cards and 
the community cards, the probabilities of the opponent holding a hand of each possible type, as well as the probability of victory. It
will also show the best hand the player can make. 

The rules have been simplified to assume all community cards on visible on the table, and that all hands of equal rank are equivalent, 
rather than involving high card rules. 

Player's cards and table cards are hardcoded. These can be changed within main of the program.

### Compilation:
*Note this program works with python2.7 as well as python3.x

python poker.py

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathPoker.JPG "Poker probabilities")

## Truth
Given a binary expression, prints the truth table. 

The four expressions checked in this program are as follows:
+ (a+(~a * (~b+b))) * b
+ ~(a+b * c) + a * (b+~c)
+ (a+b) * (a * c+a * ~c) + a * b + b
+ (a * b * c * d)+(a * b * c * ~d)+(a * b * ~c * d)+(a * b * ~c * ~d)+(a * ~b * c * d)+(a * ~b * c * ~d)+(a * ~b * d)

### Compilation:
*Note this program works for python2.7 and python3.x

python truth.py

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathTruth.JPG "Truth Tables")

## Binary Search Tree
Implements a Binary Search Tree to sort and display an address book sorted by contact's last name. Full readme can be found [here](https://github.com/NotQuiteHeroes/SchoolProjects/blob/master/AppliedDiscreteMath/BinarySearchTree/README.md)

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathBST.JPG "Binary Search Tree Sort")

## Deferred Acceptance Algorithm
Implements Gale-Shapely algorithm for deferred acceptance (or stable marriage problem). Given students and their list of instructors,
ordered by preference, as well as instructors and their own list of preferences for students, create a stable match of all students and 
instructors. Full readme can be found [here](https://github.com/NotQuiteHeroes/SchoolProjects/blob/master/AppliedDiscreteMath/Deferred%20Acceptance%20Algorithm/README.md)

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathDAA1.JPG "Deferred Acceptance input")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathDAA2.JPG "Deferred Acceptance Matching")

## Monopoly
Implements a finite state machine to go through the motions of a single player's turn in monopoly. Will roll dice and either move the
given spaces then end turn, or if doubles are rolled go through the steps to roll again, move again, and end turn or roll a third time if doubles are achieved once more. If doubles are rolled for a third time, the player will go to jail and their turn will end. Full readme can be found [here](https://github.com/NotQuiteHeroes/SchoolProjects/blob/master/AppliedDiscreteMath/Monopoly/README.md)

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathMonopoly.JPG "One player's turn in monopoly")

## RSA
Given an encoded message and certain information, such as the public key, and previous encoding knowledge, this program will decipher
a given text (encoded.txt). Encoding and Decoding follows the RSA system. Full readme can be found [here](https://github.com/NotQuiteHeroes/SchoolProjects/blob/master/AppliedDiscreteMath/RSA/README.md)

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathRSA.JPG "RSA decoding")

## Turing Machine
Simulates a classic Turing Machine. Gathers input from the user and determines if the input matches the hardcoded grammar of a^x b^y c^x. Determination involves a finite state machine. Results are displayed as either Tape Rejected or Tape Accepted. Full readme can be found [here](https://github.com/NotQuiteHeroes/SchoolProjects/blob/master/AppliedDiscreteMath/Turing%20Machine/README.md)

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathTuring.JPG "Turing Machine to check Grammar")
