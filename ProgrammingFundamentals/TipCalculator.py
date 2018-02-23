# Paige Eckstein
# 7/19/2015
# Write a program that will calculate a 20% tip and a 6%
# tax on a meal price. The user will enter the meal
# price and the program will calculate tip, tax, and the
# total. The total is the meal price plus the tip plus
# the tax.

# This is the main function


def main():
    print('Welcome to the meal calculator program')
    print
    mealprice = input_meal()
    tip = calc_tip(mealprice)
    tax = calc_tax(mealprice)
    total = calc_total(mealprice, tip, tax)
    print_info(mealprice, tip, tax, total)

# This inputs the meal total


def input_meal():
    mealprice = float(input('Enter the meal price $'))
    return mealprice


# This calculates the tip at 20%
def calc_tip(mealprice):
    tip = mealprice * .20
    return tip

# This calculates the tax at 6%


def calc_tax(mealprice):
    tax = mealprice * .06
    return tax

# This calculates the total bill


def calc_total(mealprice, tip, tax):
    total = mealprice + tip + tax
    return total

# This prints everything


def print_info(mealprice, tip, tax, total):
    print('The meal price is $%.2f' % mealprice)
    print('The tip is $%.2f' % tip)
    print('The tax is $%.2f' % tax)
    print('The total is $%.2f' % total)


# This calls main
main()
