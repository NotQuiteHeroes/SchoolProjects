/**
 * Paige Eckstein
 * Software Systems Engineering
 *
 * Book class holds very basic information about a book, such as author, title,
 * and price. It has a default constructor for use with empty initialization
 * of Member objects, and a non-default constructor that requires Title, author,
 * and Price for creation. Also includes getters for all fields.
 *
 * Requirements:
 * none
 *
 * Compilation:
 * g++ *.cpp
 *
 * Execution:
 * a.exe
 *
 * To be used with Member class, tested with BookMemberTest
 */
#include "Book.h"

/**
 * [Book::Book non-default constructor for Book object. Requires book title,
 * author, and price]
 * @param _title  [title of book, string]
 * @param _author [author of book, string]
 * @param _price  [price of book, double]
 */
Book::Book(std::string _title, std::string _author, double _price)
{
        title = _title;
        author = _author;
        price = _price;
}

/**
 * [Book::getAuthor getter for book author]
 * @return [author of book, string]
 */
std::string Book::getAuthor()
{
        return author;
}

/**
 * [Book::getTitle getter for book title]
 * @return [book title, string]
 */
std::string Book::getTitle()
{
        return title;
}

/**
 * [Book::getPrice getter for book price]
 * @return [book price, double]
 */
double Book::getPrice()
{
        return price;
}

/**
 * [Book::Book non-default constructor
 * only used for initialization of new Member objects]
 */
Book::Book()
{
}
