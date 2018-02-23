# Paige Eckstein
# 7/19/15
# This program demonstrates how to use variables and functions

# The main function


def main():
    print('Welcome to the variable program')
    print  # prints a blank line
    name = inputName()
    age = inputAge()
    print('Hello', name, age)

# This function inputs name


def inputName():
    name = str(input('Enter your name: '))
    return name

# This function inputs age


def inputAge():
    age = int(input('Enter your age: '))
    return age


# Calls main
main()
