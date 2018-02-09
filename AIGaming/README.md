# Introduction to A.I. for Gaming

The focus of this class was basic A.I. for video games, finite state machines, and path finding algorithms. 

## Bubble Sort
This is a simple bubble sort algorithm implemented in C++.

### Compilation:
g++ bubbleSort.cpp

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/bubbleSortAI.JPG "Basic Bubble Sort")

## Dungeon Crawler
This is my final project for A.I. for Gaming. 

It is a command line game where the user can choose one of four characters
--Barbarian, Wizard, Elf, or Goblin. The non-chosen characters will become the A.I. opponents. 

A map is displayed where '.' represents a free space to move, and '0' represents a wall. 

Treasure is randomly placed on the map in the form '#'. 

Each character's position is shown on the map as the first letter of the character type. The player can move by using the
wasd keys, and the A.I. characters use path finding algorithms to find the quickest path to either an enemy, or to 
treasure. 

When an A.I. character is killed its stats will re-roll, and they will be randomly placed on the map to begin
again. The game ends when the player is killed. 

Character stats are randomly rolled, with certain modifiers added depending on the character type.
Typing 'info' at any point will show the player's current stats.

Player attacks and A.I. movement and attacks are handled by a finite state machine.

## Compilation:
g++ *.cpp

## Usage:

### Beginning a Game:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/dungeonCrawlerOpening.JPG "Starting the Game")

### Viewing Player Stats:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/dungeonCrawlerInfo.JPG "View stats")

### Finding Treasure:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/dungeonCrawlerTreasure.JPG "Finding Treasure")

### Attacking:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/dungeonCrawlerAttack.JPG "Attacking")

### Killing an A.I. Character
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/dungeonCrawlerKillChar.JPG "Killing a Bot")
