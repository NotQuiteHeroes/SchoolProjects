# Computer Systems

The focus of this class was computer architecture, memory management, and a few programming assignments written in C centered around binary numbers. 

## Input Output
This program illustrates reading and writing with files in C. It requires a file called binaryFile.txt that contains a single binary number. The program reads this binary number from the file, converts it to decimal format, then writes the converted form to the file. 

### Compilation:
gcc InputOutput.c

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/compIO.JPG "File reading and writing with C")

## ASM with C
This program illustrates writing inline assembly with C. This program was compiled using GCC, and thus the assembly follows the AT&T syntax. The program will obtain two binary numbers from the user, the first being the base, and the second being the exponent. The program will then raise the base to the power in standard C, followed by raising the base to the power in assembly. 

### Compilation:
gcc ASMwithC.c

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/compASMPow.JPG "Exponential Math")

## ASM with C add
This program illustrates adding two numbers using inline assembly in C. As this program was compiled using GCC, the assembly follows the AT&T syntax. The numbers to add are hardcoded for testing purposes. 

### Compilation:
gcc ASMwithCadd.c

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/compASMAdd.JPG "Adding with Assembly")

## Binary Calculator
This program performs addition, subtraction, and multiplication on binary numbers. It only takes two binary numbers, both input by the user, and outputs the results in binary format. 

### Compilation:
gcc BinaryCalculator.c

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/compBinary.JPG "Binary Calculator")

## Decimal To Hex and Bin
This program asks the user for a decimal number, then converts it to both its binary and hexadecimal format and displays the conversion.

### Compilation:
gcc DecimalToHexandBin.c

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/compConvert.JPG "Conversion")

