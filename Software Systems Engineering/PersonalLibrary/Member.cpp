/**
 * Paige Eckstein
 * Software Systems Engineering
 * Member class holds bookstore member information, such as name, id,
 * size of personal collection, cost of total collection, newest book
 * purchased, oldest book purchased, most expensive book purchased,
 * and least expensive book purchased.
 * Includes methods to work on above information, such as add and update.
 *
 * Requirements:
 * Book.h
 *
 * Compilation:
 * g++ *.cpp
 * Execution:
 * a.exe
 *
 * To be tested with BookMemberTest.cpp
 *
 */
#include "Member.h"
#include <iostream>

/**
 * [Member::Member Member constructor for new member, only requires member
 * id number in form of int. Will ask for first and last name upon creation
 * and initialize all variables to their empty counterpart]
 * @param _id [description]
 */
Member::Member(long int _id)
{
        std::cout << "What is your first name?"<<std::endl;
        std::cin >> firstName;
        std::cout << "What is your last name?"<<std::endl;
        std::cin >> lastName;
        id = _id;
        sizeOfLibrary = 0;
        costOfLibrary = 0;
        leastExpensive = Book();
        mostExpensive = Book();
        oldest = Book();
        newest = Book();
}

/**
 * [Member::Member Member constructor for new member, requires first and last
 * name in string format, as well as id in int form. Initializes all variables
 * to their empty counterpart.]
 * @param _firstName [Member's first name, String]
 * @param _lastName  [Member's last name, String]
 * @param _id        [Member's ID, int]
 */
Member::Member(std::string _firstName, std::string _lastName, long int _id)
{
        firstName = _firstName;
        lastName = _lastName;
        id = _id;
        sizeOfLibrary = 0;
        costOfLibrary = 0;
        leastExpensive = Book();
        mostExpensive = Book();
        oldest = Book();
        newest = Book();
}

/**
 * [Member::setFirstName Member's first name setter]
 * @param _firstName [Member's first name, String]
 */
void Member::setFirstName(std::string _firstName)
{
        firstName = _firstName;
}

/**
 * [Member::setLastName Member's last name setter]
 * @param _lastName [Member's last name, String]
 */
void Member::setLastName(std::string _lastName)
{
        lastName = _lastName;
}

/**
 * [Member::updateLibrarySize Adds to number of books in personal library
 * to be used when adding books to member's library]
 * @param numOfBooks [Number of books to add to member's personal library, int]
 */
void Member::updateLibrarySize(int numOfBooks)
{
        sizeOfLibrary += numOfBooks;
}

/**
 * [Member::addBook Add a book to the member's personal library. Checks if
 * book is most/least expensive to update fields holding this information.
 * Also updates newest book added field.]
 * @param book [Book object to add to personal library, Book]
 */
void Member::addBook(Book book)
{
        //check if new book is most expensive
        if(book.getPrice() > mostExpensive.getPrice())
        {
                mostExpensive = book;
        }

        //check if new book is least expensive
        if(book.getPrice() < leastExpensive.getPrice())
        {
                leastExpensive = book;
        }

        //if this is the first book added to the library...
        if(sizeOfLibrary == 0)
        {
                //then the first book becomes the oldest, and both most
                //expensive and least expensive book as well
                oldest = book;
                mostExpensive = book;
                leastExpensive = book;
        }
        //set book to newest added to library
        newest = book;
        //add book to member's personal library
        library.push_back(book);
}

/**
 * [Member::updateCost Updates total cost of personal library. To be used when
 * a new book is added to personal library.]
 * @param cost [Cost of book purchase, double]
 */
void Member::updateCost(double cost)
{
        costOfLibrary += cost;
}

/**
 * [Member::getName Member full name getter.]
 * @return [Returns member's first and last name as a single String]
 */
std::string Member::getName()
{
        return firstName + " " + lastName;
}

/**
 * [Member::getSizeOfLibrary Gets the total number of books in personal library]
 * @return [total cost of all books in library, double]
 */
int Member::getSizeOfLibrary()
{
        return sizeOfLibrary;
}

/**
 * [Member::getBook get individual book from personal library]
 * @param  pos [position in library (vector) to get book from]
 * @return     [single Book object]
 */
Book Member::getBook(int pos)
{
        return library.at(pos);
}

/**
 * [Member::getCostOfLibrary Get total cost of personal library]
 * @return [Total cost of personal library, double]
 */
double Member::getCostOfLibrary()
{
        return costOfLibrary;
}

/**
 * [Member::getID Member's ID getter]
 * @return [return member's ID, int]
 */
int Member::getID()
{
        return id;
}

/**
 * [Member::getMostExpensive Get the most expensive book in personal library]
 * @return [most expensive book, Book object]
 */
Book Member::getMostExpensive()
{
        return mostExpensive;
}

/**
 * [Member::getLeastExpensive Get the least expensive book in personal library]
 * @return [least expensive book, Book object]
 */
Book Member::getLeastExpensive()
{
        return leastExpensive;
}

/**
 * [Member::getOldest Get oldest book in personal library]
 * @return [oldest (purchase order) book, Book object]
 */
Book Member::getOldest()
{
        return oldest;
}

/**
 * [Member::getNewest Get newest book in personal library]
 * @return [newest (purchase order) book, Book Object]
 */
Book Member::getNewest()
{
        return newest;
}
