names = []
addresses = []
numbers = []
MAXSIZE = 100
totalEntries = 0


def main():
    answer = int(
        input("1. Enter Information\n2. Search\n3.Print All Records\n"))
    if(answer == 1):
        record()
    elif(answer == 2):
        search()
    elif(answer == 3):
        printAll()
    else:
        print("Invalid input. Try again.\n")
        main()


def record():
    full = False
    index = 0
    global totalEntries

    names.append(input("Enter name:\n"))
    addresses.append(input("Enter address:\n"))
    numbers.append(input("Enter number:\n"))
    index += 1
    totalEntries = totalEntries + 1
    goAgain = input("Would you like to enter another person?\n")
    if(goAgain == "no"):
        main()
    else:
        if(index > MAXSIZE):
            print("Cannot store, address book full.\n")
            full = True
            main()
        record()


def search():
    found = False
    index = 0
    searchTerm = input("Enter name to search for:\n")
    while(found == False and index < MAXSIZE):
        if(names[index] == searchTerm):
            found = True
            print(names[index] + "\n" + addresses[index] +
                  "\n" + numbers[index] + "\n")
            main()
        else:
            index += 1
    if(found == False and index > MAXSIZE):
        print("Name not found.\n")
        main()


def printAll():
    index = 0
    while(index < totalEntries):
        print(names[index] + "\t" + addresses[index] +
              "\t" + numbers[index] + "\n")
        index += 1


main()
