import sys


def main():
    operands = []
    memory = 0
    instructions()
    menu_input(operands, memory)


def instructions():
    instructions = "Welcome to the calculator.\n To access memory at any time, type memory in the prompt. \nTo save the last number to memory, type save. \nTo clear the memory, type clear.\nTo see the number stored in memory, type print.\nTo use the number stored in memory, simply use the word memory in place of the digit. \n To see these instructions at any time, type instructions into the prompt.\n"
    print instructions


def menu_input(operands, memory):
    menuSelection = raw_input(
        "Please choose an operation:\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4.Division\n\t5.Exponentiation\n\t6. Quit\n")
    if(menuSelection.lower() == "instructions"):
        instructions()
        menu_input(operands, memory)
    elif(menuSelection.lower() == "print"):
        print memory
        menu_input(operands, memory)
    elif(int(menuSelection) == 1):
        getOperands(operands, memory)
        add(operands, memory)
    elif(int(menuSelection) == 2):
        getOperands(operands, memory)
        subtract(operands, memory)
    elif(int(menuSelection) == 3):
        getOperands(operands, memory)
        multiply(operands, memory)
    elif(int(menuSelection) == 4):
        getOperands(operands, memory)
        divide(operands, memory)
    elif(int(menuSelection) == 5):
        exponent(memory, operands)
    elif(int(menuSelection) == 6):
        goAgain(operands, memory)
    else:
        print("Invalid input. Try again.\n")
        menu_input(operands, memory)


def getOperands(operands, memory):
    del operands[:]
    size = input("How many numbers will you be using?\n")
    print("Enter each number one at a time. Press enter after each number.")
    for i in range(0, size):
        operands.insert(i, input())
        if(operands[i] == "memory"):
            operands.insert(i, memory)


def add(operands, memory):
    totalAdd = 0
    for j in range(0, len(operands)):
        totalAdd += operands[j]
    endResult(totalAdd, memory, operands)


def subtract(operands, memory):
    totalSubtract = 0
    tempSub = 0
    for k in range(0, len(operands) - 1):
        tempSub = operands[k] - operands[k + 1]
        totalSubtract += tempSub
    endResult(totalSubtract, memory, operands)


def multiply(operands, memory):
    totalMultiply = 0
    tempMult = 0
    for m in range(0, len(operands) - 1):
        tempMult = operands[m] * operands[m + 1]
        totalMultiply += tempMult
    endResult(totalMultiply, memory, operands)


def divide(operands, memory):
    totalDivide = 0
    tempDiv = 0
    for n in range(0, len(operands) - 1):
        if(operands[n] == 0):
            print("Error. Cannot divide by zero. Try again.\n")
            menu_input(operands, memory)
        tempDiv = operands[n] / operands[n + 1]
        totalDivide += tempDiv
    endResult(totalDivide, memory, operands)


def exponent(memory, operands):
    base = input("Enter the base: \n")
    exp = input("Enter the exponent: \n")
    if(base == "memory"):
        base = memory
    if(exp == "memory"):
        exp = memory
    exponentiation = base**exp
    endResult(exponentiation, memory, operands)


def endResult(value, memory, operands):
    print("Results: %f\n" % value)
    endResult = raw_input(
        "Press enter when done viewing results, or enter any memory commands(save, clear, print)")
    if(endResult == "save"):
        memory = value
    elif(endResult == "clear"):
        memory = 0
    elif(endResult == "print"):
        print("Value currently in memory: %f\n" % memory)
    elif(endResult == "instructions"):
        instructions()
    goAgain(operands, memory)


def goAgain(operands, memory):
    answer = raw_input("Would you like to perform another calculation?\n")
    if(answer.lower() == "yes"):
        menu_input(operands, memory)
    elif(answer.lower() == "no"):
        sys.exit()
    else:
        print("Invalid input. Please enter yes or no.\n")
        goAgain()


main()
