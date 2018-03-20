# Date

This program takes a date of the year and returns the day number (1 - 365) that it falls on. It also takes leap years into account.
It will check to ensure the month and day are valid (the month is between 1 - 12, and the day is between 1 - 31). If an invalid form is encountered, the program will ask the user to enter a valid format. If the shortened year is provided (for example, 1/1/18), then it will pad the beginning with 20. 

### Accepted date formats:
+ mm-dd-yyyy
+ m-d-yy
+ m/d/yy
+ mm/dd/yyyy

Note, the date objects are hardcoded in the testfile DateTest.cpp for testing purposes.

## Compilation:
g++ Date.cpp DateTest.cpp

## Execution:
a.exe

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngDate.JPG "Day of the year")
