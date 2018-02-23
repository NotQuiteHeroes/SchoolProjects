# Paige Eckstein
# 8/23/15
# Lab 9-4 Blood Drive

# the main function


def main():
    endProgram = 1
    print()
    while endProgram == 1:
        print()

        # declare variables
        pints = [0] * 7
        totalPints = 0
        averagePints = 0.0
        highPints = 0
        lowPints = 0

        # function calls
        pints = getPints(pints)
        totalPints = getTotal(pints, totalPints)
        averagePints = getAverage(totalPints, averagePints)
        highPints = getHigh(pints, highPints)
        lowPints = getLow(pints, lowPints)
        displayInfo(averagePints, highPints, lowPints)

        endProgram = int(
            input('Do you want to end program? (Enter 1 for no or 2 for yes): '))
        while not (endProgram == 1 or endProgram == 2):
            print('Please enter a 1 or 2')
            endProgram = int(
                input('Do you want to end program? (Enter 1 for no or 2 for yes): '))

# the getPints function


def getPints(pints):
    counter = 0
    while counter < 7:
        pints[counter] = int(input('Enter pints collected: '))
        counter += 1
    return pints

# the getTotal function


def getTotal(pints, totalPints):
    counter = 0
    while counter < 7:
        totalPints = totalPints + pints[counter]
        counter += 1
    return totalPints

# the getAverage function


def getAverage(totalPints, averagePints):
    averagePints = totalPints / 7.0
    return averagePints

# the getHigh function


def getHigh(pints, highPints):
    highPints = pints[0]
    counter = 1
    while counter < 7:
        if pints[counter] > highPints:
            highPints = pints[counter]
        counter += 1
    return highPints

# the getLow function


def getLow(pints, lowPints):
    lowPints = pints[0]
    counter = 1
    while counter < 7:
        if pints[counter] < lowPints:
            lowPints = pints[counter]
        counter += 1
    return lowPints

# the displayInfo function


def displayInfo(averagePints, highPints, lowPints):
    print("The average number of pints donated is: ", averagePints)
    print("The highest pints donated is: ", highPints)
    print("The lowest pints donated is: ", lowPints)


# calls main
main()
