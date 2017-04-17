names = []
addresses = []
numbers = []
MAXSIZE = 100
totalEntries = 0


def main():
    answer = input("1. Enter Information\n2. Search\n3.Print All Records\n")
    if(answer == 1):
        record()
    elif(answer == 2):
        search()
    elif(answer==3):
        printAll()
    else:
        print("Invalid input. Try again.\n")
        main()

def record():
    global names
    global addresses
    global numbers
    global totalEntries

    full = False
    index = 0
    
    names.append(raw_input("Enter name:\n"))
    addresses.append(raw_input("Enter address:\n"))
    numbers.append(raw_input("Enter number:\n"))
    index+=1
    totalEntries+=1
    goAgain = raw_input("Would you like to enter another person?\n")
    if(goAgain == "no"):
        main()
    if(index > MAXSIZE):
        print("Cannot store, address book full.\n")
        full = True

def search():
    found = False
    index = 0
    searchTerm = raw_input("Enter name to search for:\n")
    while(found == False and index < MAXSIZE):
        if(names[index] == searchTerm):
            found = True
            print(names[index]+"\n"+addresses[index]+"\n"+numbers[index]+"\n")
            main()
        else:
            index+=1
    if(found==False and index > MAXSIZE):
        print("Name not found.\n")
        main()

def printAll():
    index = 0
    while(index < totalEntries):
        print(names[index]+"\t"+addresses[index]+"\t"+numbers[index]+"\n")
        index+=1

main()
