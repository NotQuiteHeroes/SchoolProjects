# Deferred Acceptance Algorithm (DAA) or Gale-Shapely Algorithm

Illustrates stable marriage problem solver. SMP is the problem of finding a stable matching between two equally sized sets of elements,
given an ordering of preferences for each element. A matching is a mapping of elements from the first group with the elements of the
second. 

A matching is not considered stable if:
+ There is an element A of the first matched set which prefers some given element B of the second matched set over the element to 
which A is already matched
+ B also prefers A over the element to which B is already matched.

In other words, a matching is stable when there does not exist any match (A, B) by which both A and B would be individually
better offthan they are with the element with which they are currently matched.
[wikipedia](https://en.wikipedia.org/wiki/Stable_marriage_problem) 

This code works to match up students with instructors based on both's preferences provided at run time.

## Input
Upon running, the program will ask to enter the number of students to be checked. This must be the same size as the number
of instructors to be checked. Then the user will be expected to enter the students name, followed by their list of instructor
preferences, with the first listed being the most desirable, and the last being the least desirable. The user must press enter between 
entering each student

Example input:
Student : Instructor1, Instructor2, Instructor3

## Output
The program will output each step of the algorithm, showing the student requesting a match with the instructor, and the instructor's
response (acceptance or refusal). It will then print the current matches of each student and instructor before repeating the
student request. When all students are matched with an instructor, the final matched pairs will be displayed.

## Execution:
For Python2.7, use daa2.py

python2.7 daa2.py

For Python3.x, use daa3.py

python daa3.py

## Usage:
Enter student's and instructor's names and preferences:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathDAA1.JPG "Adding preferences")

Results:

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathDAA2.JPG "Matches")
