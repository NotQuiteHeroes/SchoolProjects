# Paige Eckstein
# July 12, 2015
# This program will return the student's name, degree, and credits remaining.

studentName = str(input("Enter student name "))
studentDegree = str(input("Enter degree "))

creditsDegree = int(
    input("Enter the number of credits required for the degree "))
creditsTaken = int(input("Enter the number of credits already taken "))

creditsLeft = creditsDegree - creditsTaken

print('The student\'s name is ', studentName)
print('The degree name is ', studentDegree)
print('There are ', creditsLeft, ' left until graduation.')
