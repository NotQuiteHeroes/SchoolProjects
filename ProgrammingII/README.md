# Programming II
The main focus of this class was intermediate C++. The final project was creating a command line version of Tetris, which can be found [here](https://github.com/NotQuiteHeroes/CommandLineTetris). Other topics include use of standard library, random number generation, and object oriented principles such as inheritance and virtual methods.

## Keypad 
This program, when given a number between 0 - 999, will return the next highest number that does not include a 1, 4, or a 7.

### Compilation:
g++ keypad.cpp

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIIkeypad.JPG "Find the next highest number that doesn't contain a 1, a 4, or a 7.")

## List Example
This program demonstrates the use of the list container from the standard library. It creates a Student struct that contains an operator overloader to sort student names. It then creates a list and populates it with Student objects, then sorts the list.

### Compilation:
g++ listExample.cpp

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIIListExample.JPG "Standard library list example")

## Mastermind
This is a command line version of the game Mastermind using five digits. The program generates a random string of five integers. The player guesses five number combinations, and receives an answer key that corresponds to each digit guessed. In the answer key, 1 means right number, right place. 2 means right number, wrong place. 3 means number is not in the answer.

### Compilation:
g++ mastermind.cpp

## Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIIMastermind.JPG "Command Line Mastermind Game")

## Virtual Example
This program illustrates basic inheritance and implementation of a virtual method. It contains a base Person class that contains information on an individual's name, address, city, state, zip, and phone number. It implements a virtual display method. The program also contains two child classes, Student and Professional, that both inherit from the base Person class, and implement a non-virtual version of the display method.

### Compilation:
g++ virtualExample.cpp

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIIVirtualExample.JPG "Inheritance and virtual methods")

