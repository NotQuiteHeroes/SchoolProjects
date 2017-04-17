#Paige Eckstein
#8/9/15
#Randomly generates dice throws and displays a winner

import random

#the main function
def main():
    print
    #initialize variables
    endProgram = 'no'
    playerOne, playerTwo = 'NO NAME', 'NO NAME'

    #call to inputNames
    playerOne, playerTwo = inputNames(playerOne, playerTwo)

    #while loop to run program again
    while endProgram == 'no':

        #initialize variables
        winnerName = 'NO NAME'
        p1number, p2number = 0, 0

        #call to rollDice
        winnerName = rollDice(p1number, p2number, playerOne, playerTwo, winnerName)

        #call to displayInfo
        displayInfo(winnerName)

        endProgram = raw_input('Do you want to end program? (Enter yes or no): ')
    
#This function gets the player's names
def inputNames(playerOne, playerTwo):
     playerOne = raw_input("Player 1: Please enter your name: ")
     playerTwo = raw_input("Player 2: Please enter your name: ")
     return playerOne, playerTwo

#This function will get the random values
def rollDice(p1number, p2number, playerOne, playerTwo, winnerName):
    p1number = random.randint(1, 6)
    p2number = random.randint(1, 6)
    if p1number == p2number:
        winnerName = "Tie"
    elif p1number > p2number:
        winnerName = playerOne
    else:
        winnerName = playerTwo
    return winnerName

#This function displays the winner
def displayInfo(winnerName):
    print(winnerName)
    
#calls main
main()
