# Paige Eckstein
# 9/6/2015
# Lab 10-3 Blood Drive

# The main function


def main():
    endProgram = 1
    print
    while endProgram == 1:
        option = 0
        print
        print("Enter 1 to enter in new data and store to file")
        print("Enter 2 to display data from the file.")
        option = int(input("Enter now ->"))
        print

        # declare variables
        pints = [0] * 7
        totalPints = 0
        averagePints = 0

        if option == 1:
            pints = getPints(pints)
            totalPints = getTotal(pints, totalPints)
            averagePints = getAverage(totalPints, averagePints)
            writeToFile(averagePints, pints)
        if option == 2:
            readFromFile(averagePints, pints)
        else:
            endProgram = int(
                input("Do you want to end program? (Enter 1 for no or 2 for yes): "))
            while not (endProgram == 2 or endProgram == 1):
                print('Please enter a 1 or 2')
                endProgram = int(
                    input("Do you want to end program? (Enter 1 for no or 2 for yes): "))

# the getPints function


def getPints(pints):
    counter = 0
    while counter < 7:
        pints[counter] = int(input('Enter pints collected: '))
        counter = counter + 1
    return pints

# the getTotal function


def getTotal(pints, totalPints):
    counter = 0
    while counter < 7:
        totalPints = totalPints + pints[counter]
        counter = counter + 1
    return totalPints

# the getAverage function


def getAverage(totalPints, averagePints):
    averagePints = float(totalPints) / 7
    return averagePints

# the writeToFile function


def writeToFile(averagePints, pints):
    outFile = open('blood.txt', 'a')
    outFile.write("Pints Each Hour\n")
    counter = 0
    while counter < 7:
        outFile.write(str(pints[counter]) + '\n')
        counter = counter + 1
    outFile.write("Average Pints")
    outFile.write(str(averagePints) + '\n\n')
    outFile.close()

# the readFromFile function


def readFromFile(averagePints, pints):
    inFile = open('blood.txt', 'r')
    str1 = inFile.read()
    print(str1)
    pints = inFile.read()
    print(pints)
    print
    str2 = inFile.read()
    averagePints = inFile.read()
    print(averagePints)
    inFile.close()


# calls main
main()
