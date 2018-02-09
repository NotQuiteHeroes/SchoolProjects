# LSD Sort

Least-Significant-Digit first string sort Algorithm is a type of counting sort based on key-indexing that works by counting
the number of objects having distinct key values, then using arithmetic to calculate the position of each object in the output sequence.

LSD string sort starts with the right-most character, performs the key-indexing/count, then moves to the next right-most character
and so forth in this manner.

Requires a text file containing equal length words.

## Output:
The words from the provided text file in alphabetical order.

## Files:
+ LSD: implementation
+ LSDtest: test file for LSD implementation
+ words3.txt: test text file containing equal length words

## Compilation:
javac *.java

## Execution:
java LSDtest < words3.txt

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/LSD.JPG "LSD Sort")
