# MSD Sort

Most-Significant-Digit first string sort algorithm is a type of counting sort based on key-indexing that works by
partitioning information into pieces according to the first character, then recursively sorts all strings that start with each
character.

MSD string sort starts with the left-most character, performs the key-indexing/count, then moves to the next left-most character
and so forth in this manner.

Requires a text file containing the words to be sorted, unlike LSD these do not need to be the same length.

## Output:
The words from the given text file sorted in alphabetical order.

## Files:
+ MSD: implementation
+ MSDtest: test client for implementation
+ shells.txt: text file containing words to be sorted

## Compilation:
javac *.java

## Execution:
java MSDtest < shells.txt

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/MSD.JPG "MSD sort")
