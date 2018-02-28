# Programming I

The focus of this class was intermediate C++. The programs became larger, with a focus on functions, objected oriented approaches, and the the standard library.

## Number Generator
This program creates a phone number given the following specifications:
+ Obtain first four digits from the user.
+ If the fourth number is even, the fifth number must be odd.
+ If the fourth number is odd, the fifth number must be even.
+ The last six digits must add up to total 33. 

It then prints out all phone numbers that meet the given criteria.

### Compilation:
g++ numberGenerator.cpp

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingINumberGen.JPG "Phone number generation")

## Numbers Game
This is a simple math based game. It randomly generates two numbers, picks a random operation from addition, subtraction, and multiplication, and calculates the result. It then randomly picks two of the three numbers (either of the operands, or the result) and displays them, with a blank line ___ to illustrate the missing number. The user then must guess the missing number.

### Compilation:
g++ numbersGame.cpp

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingINumberGuessing.JPG "Number Guessing Game")

## Yahtzee
This is a full game of yahtzee on the command line that can be played between 1 and 4 players. It consists of 13 rounds where each player rolls five dice. They can then decide to hold any amount of the five dice rolled, and roll again. They have one more chance to hold and re-roll before the final dice are displayed. The program then displays the scoring rules for each type of hand in Yahtzee and the player can choose which one they want to score their current dice for. The game will check if that score box has already been filled in, but it does trust the user to input the appropriate score box, as it will not check each hand for accuracy. At the end of the game, each scorecard is tallied and the winner is displayed.

### Compilation:
g++ yahtzee.cpp

### Execution:
a.exe

### Starting the Game
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIYahtzeeOpening.JPG "Start of the game")

### One Round
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIYahtzeeRound.JPG "One round in the game")

### Scoring
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/programmingIYahtzeeScoring.JPG "One round of scoring")
