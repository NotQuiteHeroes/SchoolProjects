/*
Paige Eckstein
Software Systems Engineering
3/6/2018

Television class takes information from the user for the model number, screen
size, and price of a telvision set.

It implements exception handling to ensure the model number is less than
four digits, that the screen size is less than 70 but greater than 12, and that
the price is less than 5,000.

If an exception is caught for the above conditions, all the variables will be
set to 0.

The Television class also overloads the insertion and extraction operators.

Compilation:
g++ Television.cpp televisionTest.cpp

Execution:
a.exe

No requirements beyond standard library.
 */

#ifndef __TELEVISION__
#define __TELEVISION__

#include <iostream>

class Television
{
private:
std::string model;
int size;
double price;

public:
Television();
Television(std::string _model, int _size, double _price);

void setModel(std::string _model);
void setSize(int _size);
void setPrice(double _price);

void validate(std::string model, int size, double price);

friend std::istream &operator >> (std::istream& in, Television& tv);
friend std::ostream &operator << (std::ostream& out, Television& tv);
};

#endif
