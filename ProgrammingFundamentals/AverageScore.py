#Paige Eckstein
#8/15/15
#Lab 6-4 Test Score Averages rewritten for lab 8-4

#the main function
def main():
    endProgram = 'no'
    print
    while endProgram == 'no':
        totalScores = 0
        averageScores = 0
        number = 0
        number = getNumber(number)
        totalScores = getScores(totalScores, number)
        averageScores = getAverage(totalScores, averageScores, number)
        printAverage(averageScores)
        endProgram = raw_input('Do you want to end program? (Enter no to process a new set of scores or yes to exit: ')
        while endProgram.lower() != 'yes' and endProgram.lower() != 'no':
            print("Not a valid answer, please type 'yes' or 'no': ")
            endProgram = raw_input()
            
#this function will determine how many students took the test
def getNumber(number):
    number = input('How many students took the test: ')
    while number < 2 or number > 30:
        print("Not a valid number, please enter a number between 2 and 30")
        number = input()
    return number

#this function will get the total scores
def getScores(totalScores, number):
    for counter in range(0, number):
        score = input('Enter their score: ')
        while score < 0 or score > 100:
            print("Not a valid score, please enter a number between 0 and 100")
            score = input()
        totalScores = totalScores + score
    return totalScores

#this function will calculate the average
def getAverage(totalScores, averageScores, number):
    averageScores = totalScores / number
    return averageScores

#this function will display the average
def printAverage(averageScores):
    print 'The average test score is', averageScores  
    
# calls main
main()
