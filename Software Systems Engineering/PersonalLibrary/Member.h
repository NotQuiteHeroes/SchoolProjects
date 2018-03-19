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
#ifndef __AMEMBER__
#define __AMEMBER__

#include <vector>
#include "Book.h"

class Member
{
private:
std::vector<Book> library;
std::string firstName;
std::string lastName;
long int id;
int sizeOfLibrary;
double costOfLibrary;
Book mostExpensive;
Book leastExpensive;
Book newest;
Book oldest;

public:
Member(long int _id);
Member(std::string _firstName, std::string _lastName, long int _id);
void setFirstName(std::string _firstName);
void setLastName(std::string _lastName);
void updateLibrarySize(int numOfBooks);
void addBook(Book book);
void updateCost(double cost);
std::string getName();
int getSizeOfLibrary();
Book getBook(int pos);
double getCostOfLibrary();
int getID();
Book getMostExpensive();
Book getLeastExpensive();
Book getOldest();
Book getNewest();
};

#endif //__MEMBER__
