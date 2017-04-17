def main():
    gallon = .0625
    quart = .25
    pint = .5
    tbsp = 16
    tsp = 48

    cups = input("Enter number of cups to convert:\n")

    print("Gallon(s):     %f\n" % (gallon*cups))
    print("Quart(s):      %f\n" % (quart*cups))
    print("Pint(s):       %f\n" % (pint*cups))
    print("Tablespoon(s): %f\n" % (tbsp*cups))
    print("Teaspoon(s):   %f\n" % (tsp*cups))

main()
