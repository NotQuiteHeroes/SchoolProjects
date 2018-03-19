/**
 * Paige Eckstein
 * Software Systems Engineering
 * BookMemberTest is test file for Member.cpp and Book.cpp classes
 * Provides front-end usage to test member and book.
 * Begins by creating a new Member object, then offer
 * the member a menu of options:
 * 1. Add Book
 * 2. View Library stats
 * 3. View all books
 * 4. View member information
 * 5. Update member information
 * 6. Exit.
 *
 * Add book allows the user to add a new book to their personal Library
 *
 * View library stats gives information on total number of books in library,
 * total cost of all books in personal library, the newest book purchased, the
 * oldest book purchased, the cheapest book purchased, and the most expensive
 * book purchased
 *
 * View all books prints out title, author, and price information for all
 * books in personal library
 *
 * View member information prints member name, id, total number of books in
 * personal library, and total spent on personal library
 *
 * Update member information allows the user to modify their first name and/or
 * last name
 *
 * Exit quits the program.
 *
 * Requires:
 * Member.h
 *
 * Compilation:
 * g++ *.cpp
 *
 * Execution:
 * a.exe
 */
#include "Member.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void displayMenu(Member &member);
void addBook(Member &member);
void viewStats(Member &member);
void viewLibrary(Member &member);
void viewMemberStats(Member &member);
void updateInfo(Member &member);

int main()
{
        cout << "========================================"<<endl;
        cout << "=============Library Manager============"<<endl;
        cout << "========================================"<<endl;
        //create member object with id number
        Member member1(45812);
        cout << "========================================"<<endl;
        displayMenu(member1);
        return 0;
}

/**
 * [displayMenu Main menu for member to interact with program]
 * @param member [reference to member object that is using program]
 */
void displayMenu(Member &member)
{
        int choice;
        cout << "1. Add Book."<<endl;
        cout << "2. View Library Stats."<<endl;
        cout << "3. View All Books."<<endl;
        cout << "4. View Member Information."<<endl;
        cout << "5. Update Member Information."<<endl;
        cout << "6. Exit."<<endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
                addBook(member);
                break;
        case 2:
                viewStats(member);
                break;
        case 3:
                viewLibrary(member);
                break;
        case 4:
                viewMemberStats(member);
                break;
        case 5:
                updateInfo(member);
                break;
        case 6:
                cout << "Goodbye!"<<endl;
                exit(0);
        default:
                displayMenu(member);
        }
}

/**
 * [addBook Add a book to member's personal library]
 * @param member [reference to member object using the program]
 */
void addBook(Member &member)
{
        string tempTitle;
        string tempAuth;
        double tempPrice;
        //get book information from member
        cout << "Enter book title: "<<endl;
        cin.ignore();
        getline(cin, tempTitle);
        cout << "Enter author: "<<endl;
        getline(cin, tempAuth);
        cout << "Enter price: "<<endl;
        cin >> tempPrice;

        //create Book object with acquired information
        Book book(tempTitle, tempAuth, tempPrice);
        //add book to member's personal library
        member.addBook(book);
        //increase library size to accomodate new book added
        member.updateLibrarySize(1);
        //increase library cost to accomodate new book added
        member.updateCost(tempPrice);
        displayMenu(member);
}

/**
 * [viewStats displays information about member's personal library:
 * includes total number of books in personal library, total cost of personal
 * library, oldest book in library, newest book in library, most Expensive
 * book in library, and least expensive book in library]
 * @param member [reference to member object using the program]
 */
void viewStats(Member &member)
{
        cout << "-------------------------------"<<endl;
        cout << "---------Library Info----------"<<endl;
        cout << "-------------------------------"<<endl;
        cout << "Number of Books in Library: "<<endl;
        cout << member.getSizeOfLibrary() << endl;
        cout << "Total Cost of Library: "<<endl;
        cout << member.getCostOfLibrary() << endl;
        cout << endl;
        cout << "Oldest Book in Library: "<<endl;
        cout << member.getOldest().getTitle()<<endl;
        cout << member.getOldest().getAuthor()<<endl;
        cout << member.getOldest().getPrice()<<endl;
        cout << endl;
        cout << "Newest Book in Library: "<<endl;
        cout << member.getNewest().getTitle()<<endl;
        cout << member.getNewest().getAuthor()<<endl;
        cout << member.getNewest().getPrice()<<endl;
        cout << endl;
        cout << "Most Expensive Book in Library: "<<endl;
        cout << member.getMostExpensive().getTitle()<<endl;
        cout << member.getMostExpensive().getAuthor()<<endl;
        cout << member.getMostExpensive().getPrice()<<endl;
        cout << endl;
        cout << "Least Expensive Book in Library: "<<endl;
        cout << member.getLeastExpensive().getTitle()<<endl;
        cout << member.getLeastExpensive().getAuthor()<<endl;
        cout << member.getLeastExpensive().getPrice()<<endl;
        cout << "-------------------------------"<<endl;
        displayMenu(member);
}

/**
 * [viewLibrary Display all books in personal library]
 * @param member [reference to member object using the program]
 */
void viewLibrary(Member &member)
{
        cout << "-------------------------------"<<endl;
        cout << "------------Library------------"<<endl;
        cout << "-------------------------------"<<endl;
        for(int i = 0; i < member.getSizeOfLibrary(); i++)
        {
                Book currentBook = member.getBook(i);
                cout << "Title: "<<currentBook.getTitle()<<endl;
                cout << "Author: "<<currentBook.getAuthor()<<endl;
                cout << "Price: $"<<currentBook.getPrice()<<endl;
                cout << "-------------------------------"<<endl;
        }
        cout << "-------------------------------"<<endl;
        displayMenu(member);
}

/**
 * [viewMemberStats Display member stats information:
 * first name, last name, id number, total number of books in personal library
 * and total spent on personal library]
 * @param member [reference to member object currently using program]
 */
void viewMemberStats(Member &member)
{
        cout << "-------------------------------"<<endl;
        cout << "----------Member Info----------"<<endl;
        cout << "-------------------------------"<<endl;
        cout << "Name: " << member.getName()<<endl;
        cout << "Id: " << member.getID()<<endl;
        cout << "Number of Books in Library: "<<member.getSizeOfLibrary()<<endl;
        cout << "Total Spent: "<<member.getCostOfLibrary()<<endl;
        cout << "-------------------------------"<<endl;
        displayMenu(member);
}

/**
 * [updateInfo update member firstname and/or last name]
 * @param member [reference to member object using the program]
 */
void updateInfo(Member &member)
{
        string firstName, lastName;
        cout << "Enter Member's First Name: "<<endl;
        cin >> firstName;
        cout << "Enter Member's Last Name: "<<endl;
        cin >> lastName;
        member.setFirstName(firstName);
        member.setLastName(lastName);
        displayMenu(member);
}
