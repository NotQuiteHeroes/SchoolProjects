# Paige Eckstein
# 7/28/15
# The Bottle Return Program takes the number of bottles returned in a week
# and returns the total payout for said bottles

# the main function


def main():
    endProgram = 1
    while endProgram == 1:
        totalBottles = getBottles()
        totalPayout = calcPayout(totalBottles)
        printInfo(totalBottles, totalPayout)
        endProgram = int(
            input('Do you want to end the program? (Enter 1 for no or 2 for yes): '))

# this function will get the number of bottles returned


def getBottles():
    totalBottles = 0
    todayBottles = 0
    counter = 1
    while counter <= 7:
        todayBottles = int(input('Enter number of bottles for today: '))
        totalBottles = totalBottles + todayBottles
        counter = counter + 1
    return totalBottles

# this function will calculate the payout


def calcPayout(totalBottles):
    totalPayout = 0
    totalPayout = totalBottles * .10
    return totalPayout

# this function will display the information)


def printInfo(totalBottles, totalPayout):
    print('The total number of bottles collected is', totalBottles)
    print('The total paid out is $%.2f' % totalPayout)


# calls main
main()
