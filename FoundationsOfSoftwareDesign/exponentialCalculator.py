import sys

def main():
  getNumbers()
  goAgain()

def getNumbers():
  base = exponent = 0
  base = input("Enter the base:\n")
  exponent = input("Enter the exponent:\n")

  if(base >= 2147483647e10 or exponent >= 2147483647e10):
    print("Invalid input. Please enter a number smaller than 2147483647e10.\n")
    getNumbers()

  calculations(base, exponent)

def calculations(base, exponent):
  result = 0
  result = base**exponent
  if(result >= 2147483647e10):
    print("Result is too large to store, please try with different numbers.\n")
    main()
  print("Results: %f" % result)

def goAgain():
  again = raw_input("Would you like to perform another operation?\n")
  if(again.lower() == "yes"):
    main()
  elif(again.lower() == "no"):
    sys.exit()
  else:
    print("Invalid input. Please enter yes or no\n")
    goAgain()

main()
