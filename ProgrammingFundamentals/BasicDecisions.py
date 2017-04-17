# Paige Eckstein
# 7/26/2015
# This program will demonstrate how to use decision
# statements in Python

# This program determines if a bonus should be awarded

#The main function
def main():
    print 'Welcome to the program'
    monthlySales = getSales()     # gets sales
    isBonus(monthlySales)         # checks for bonus eligibility
    dayOff(monthlySales)          # checks for day off eligibility
    
#This function gets the monthly sales
def getSales():
    monthlySales = input('Enter the monthly sales $')
    monthlySales = float(monthlySales)  #converts to floating point
    return monthlySales

#This function checks if bonus eligibility is met
def isBonus(monthlySales):
    if monthlySales >= 100000:
        print "You have earned a $5,000 bonus!!!"

#This function checks if employees get a day off
def dayOff(monthlySales):
    if monthlySales >= 112500:
        print 'Everyone gets a day off!'
        

#calls main
main()
