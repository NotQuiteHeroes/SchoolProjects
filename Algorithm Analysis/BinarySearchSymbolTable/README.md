# Binary Search Symbol Table

BinarySearchST illustrates a symbol table implemented with a binary search tree.

Takes input in form of file with letters given one per line.

### Output:

size = x

min = A

max = Y

keys()

A 8

B 0

C 10

etc. for each key and its corresponding last found position

select()

0 A

1 B

2 C

etc. for each key in alphabetical order, numbered for convenience

key rank floor ceiling

A 0 A A

B 1 B B

C 2 C C

D 3 C E

etc. for each letter in the alphabet (key) where rank is the number of keys in the symbol table that are strictly
less than the key

floor is the largest key in the symbol table that is less than or equal to the key and ceiling is the smallest key
in the symbol table that is greater than or equal to the key.

## Files:
+ BinarySearchST: implementation
+ BinarySearchSTTest: test file for BinarySearchST
+ BSTtest.txt: text file to be used with BinarySearchSTTest

## Compilation:
javac *.java

## Execution:
javac BinarySearchSTTest < BSTtest.txt

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/binarySearchSymbolTable.JPG "Binary Search Symbol Table in use")
