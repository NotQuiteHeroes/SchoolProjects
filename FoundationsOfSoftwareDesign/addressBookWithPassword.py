import csv
import os.path

SIZE = 100
names = []
addresses = []
numbers = []


def main():
    password()
    if(os.path.exists("addressBook.csv")):
        loadData()
    endProgram = ""
    while(endProgram != "yes"):
        menuOutput()
        endProgram = input("Would you like to quit? ")
    saveData()


def password():
    PASSWORD = "H3110W0r1d"
    tempPass = char1 = char2 = ""
    index = 0

    tempPass = input("Please enter the password:")

    if(len(tempPass) > len(PASSWORD)):
        print("Wrong password.\n")
        main()
    else:
        while(index < len(tempPass) - 1):
            char1 = tempPass[index]
            char2 = PASSWORD[index]
            if char1 != char2:
                print("Wrong password.\n")
                main()
            else:
                index = index + 1
    print()


def menuOutput():
    print("a. Enter Information\nb. Search\nc. Print all\nd. Sort\n")
    menuInput()


def menuInput():
    answer = ""
    answer = input("Please choose one:")
    menuLogic(answer)


def menuLogic(answer):
    if(answer == "a"):
        record()
    elif(answer == "b"):
        search()
    elif(answer == "c"):
        printAll()
    elif(answer == "d"):
        sort()
    else:
        print("I'm sorry, please type 'a', 'b', 'c', or 'd'\n")
        menuOutput()


def loadData():
    with open("addressBook.csv", 'r') as inputFile:
        fullList = [tuple(line) for line in csv.reader(inputFile)]
    total = len(fullList)
    print("total" + str(total))
    for i in range(0, total - 1, 2):
        names.append(fullList[i][0])
        addresses.append(fullList[i][1])
        numbers.append(fullList[i][2])


def record():
    total = len(names)
    addMore = ""
    while(total < SIZE and addMore != "no"):
        getInput()
        addMore = input("Would you like to add another record?\n")


def getInput():
    total = len(names)
    index = total

    names.append(input("Please enter a name: \n"))

    addresses.append(input("Please enter an address: \n"))

    numbers.append(input("Please enter a number: \n"))


def search():
    searchTerm = ""
    first = 0
    last = len(names) - 1
    position = -1
    found = False
    middle = index = scan = unsorted = 0

    searchTerm = input("Please enter a name to search for: \n")

    for index in range(0, len(names)):
        unsorted = names[index]
        scan = index

        while(scan > 0 and names[scan - 1] > unsorted):
            temp = names[scan]
            names[scan] = names[scan - 1]
            names[scan - 1] = temp

            temp = addresses[scan]
            addresses[scan] = addresses[scan - 1]
            addresses[scan - 1] = temp

            temp = numbers[scan]
            numbers[scan] = numbers[scan - 1]
            numbers[scan - 1] = temp

            scan = scan - 1

        unsorted = names[scan]

    while(not found and first <= last):
        middle = int((first + last) / 2)
        if(names[middle] == searchTerm):
            found = True
            position = middle
            print("\t" + names[middle] + "\t" +
                  addresses[middle] + "\t" + numbers[middle] + "\n")
        elif(names[middle] > searchTerm):
            last = middle - 1
        else:
            first = middle + 1


def printAll():
    index = 0
    total = len(names)

    while(index < total):
        print("\t" + names[index] + "\t" +
              addresses[index] + "\t" + numbers[index] + "\n")
        index = index + 1


def sort():
    sortType = ""
    answer = ""
    sortType = input("Plese choose ascending or descending: \n")

    total = len(names)

    if(sortType == "ascending"):
        for i in range(1, total):
            unsorted = names[i]
            scan = i
            while(scan > 0 and names[scan - 1] > unsorted):
                temp = names[scan]
                names[scan] = names[scan - 1]
                names[scan - 1] = temp

                temp = addresses[scan]
                addresses[scan] = addresses[scan - 1]
                addresses[scan - 1] = temp

                temp = numbers[scan]
                numbers[scan] = numbers[scan - 1]
                numbers[scan - 1] = temp

                scan = scan - 1
            unsorted = names[scan]
    elif(sortType == "descending"):
        for i in range(1, total):
            unsorted = names[i]
            scan = i
            while(scan > 0 and names[scan - 1] < unsorted):
                temp = names[scan]
                names[scan] = names[scan - 1]
                names[scan - 1] = temp

                temp = addresses[scan]
                addresses[scan] = addresses[scan - 1]
                addresses[scan - 1] = temp

                temp = numbers[scan]
                numbers[scan] = numbers[scan - 1]
                numbers[scan - 1] = temp

                scan = scan - 1
            names[scan] = unsorted
    answer = input("Would you like to print all now?\n")
    if(answer == "yes" or answer == "Yes"):
        printAll()


def saveData():
    total = len(names)

    with open("addressBook.csv", 'w') as outputFile:
        writer = csv.writer(outputFile, delimiter=",")
        for i in range(0, total):
            writer.writerow(((names[i], addresses[i], numbers[i])))


main()
