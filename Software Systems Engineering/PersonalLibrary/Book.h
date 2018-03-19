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
#ifndef __ABOOK__
#define __ABOOK__
#include <string>

class Book
{
private:
std::string title;
std::string author;
double price;
public:
Book (std::string _title, std::string _author, double _price);
Book();
std::string getAuthor();
std::string getTitle();
double getPrice();
};

#endif
