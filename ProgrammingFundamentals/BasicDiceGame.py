# Paige Eckstein
# 8/9/15
# Randomly generates dice throws and displays a winner

import random

# the main function


def main():
    print()
    # initialize variables
    endProgram = 1
    playerOne, playerTwo = 'NO NAME', 'NO NAME'

    # call to inputNames
    playerOne, playerTwo = inputNames(playerOne, playerTwo)

    # while loop to run program again
    while endProgram == 1:

        # initialize variables
        winnerName = 'NO NAME'
        p1number, p2number = 0, 0

        # call to rollDice
        winnerName = rollDice(p1number, p2number,
                              playerOne, playerTwo, winnerName)

        # call to displayInfo
        displayInfo(winnerName)

        endProgram = int(input(
            'Do you want to end program? (Enter 1 for no or 2 for yes): '))

# This function gets the player's names


def inputNames(playerOne, playerTwo):
    playerOne = str(input("Player 1: Please enter your name: "))
    playerTwo = str(input("Player 2: Please enter your name: "))
    return playerOne, playerTwo

# This function will get the random values


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

# This function displays the winner


def displayInfo(winnerName):
    print(winnerName)


# calls main
main()
