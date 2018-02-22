# Java I

The focus of this class was an introduction to creating GUIs with Java. There are small projects to get used to some of the Java Libraries, but the main project involved creating a Trip Calculator. This went through various iterations, from a very simple calculator that allowed the user to enter the price of gas and number of miles in trip, added to the cost of an oil change, and display the results. The final result was a GUI that allowed the user to select from a drop down menu of locations as a starting and ending point, picking the type of gas, entering the price of gas, and selecting the type of car from a drop down menu before displaying the results of the calculations. It also allows the user to pick Customize, which will take them to a different screen where they can enter the values of distance and gas price. 

## Buttons
This program shows a GUI to the user that has four buttons and a drop down containing color names. Clicking on any of the buttons, or selecting a color from the drop down menu, will change the background to match the selected color. 

### Compilation:
javac Buttons.java

### Execution:
java Buttons

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/javaIButtons.JPG "Color Buttons")

## Circumference
A simple command line application that takes the radius of a circle from the user and displays the circle's circumference

### Compilation:
javac Circumference.java

### Execution:
java Circumference.java

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/javaICircumference.JPG "Circumference")

## Color Squares
This is a simple applet that fills the screen with randomly colored squares. Requires the accompanying colorSquares.html file to run.

### Compilation:
javac colorSquares.java

### Execution:
appletviewer colorSquares.html

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/javaIcolorSquares.JPG "Random color squares")

## Print Date
This is a simple command line program that will print the current date in the form: DayOfTheWeek, Month Day, Year

### Compilation:
javac printDate.java

### Execution:
java printDate

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/javaIDate.JPG "Print current date")

## Trip Calc
This is an early version of the final project Trip Calculator. It has text fields to allow the user to enter the total number of miles the trip will take and the cost of gas. It will then add the cost of an oil change, calculate the cost for gas given the distance and price, and display the results to the user.

### Compilation:
javac tripCalc.java

### Execution:
java tripCalc

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/JavaISimpleTripCalc.JPG "Simple Trip Calculator")

## Trip Calculator v2
This is the final version of the Trip Calculator project. Its initial page displays four drop down menus - one to hold the starting point, one to hold the destination, one to hold the type of car, and one to hold the type of gas. The Submit button will perform the calculations to determine the cost of the trip plus an oil change. The Clear button clears all fields. The Customize button takes the user to a different page that has two text fields, one to enter the total miles of the trip, and one to hold the price of gas. Submit will perform the calculations, Clear will clear all fields, and Back will take the user back to the initial page.

### Compilation:
javac tripCalculatorv2.java

### Execution:
java tripCalculatorv2

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/JavaItripcalc.JPG "First page of Trip Calculator")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/javaItripcalc2.JPG "customize page")
