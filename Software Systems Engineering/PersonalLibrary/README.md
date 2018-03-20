# Personal Library

This program keeps track of an individual's personal library. It contains member information, such as first name, last name, and member id, which could be used as a library card id. It also contains the author name, book title, and book price of any books the member has purchased. The program allows the user to modify their personal information, add a book to their library, view their library stats (such as oldest book added, newest book added, most expensive book added, and least expensive book added), and view all the books in their library.

## Files:
+ Book.h/.cpp : Simple class to hold book information, such as title, author, and price. To be used in the Member's library (vector of books).
+ Member.h/cpp : Class to hold member information, such as name and id, as well as member's personal library (a vector containing Book objects). Also holds personal library information, such as newest/oldest book, and most/least expensive book.
+ BookMemberTest.cpp : testfile that implements each method from Member and displays information on member and library.

## Compilation:
g++ Book.cpp Member.cpp BookMemberTest.cpp

## Execution:
a.exe

## Usage
### Creating an account and adding a book to library:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngLibAddBook.JPG "Add book")

### Viewing library stats:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngLibInfo.JPG "Libary Info")

### Viewing member stats:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngLibMemberInfo.JPG "Member info")

### Viewing all books in library:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngLibViewBooks.JPG "All books")

### Updating member info:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/softwareEngLibUpdateInfo.JPG "Update Member Info")



