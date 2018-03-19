/**
 * Paige Eckstein
 * Software Systems Engineering
 * Roman Class
 *
 * Each object of Roman class will store
 * a Roman Numeral, then convert and store
 * its integer form.
 * Can print either form upon user request
 *
 * Tested with RomanTest.cpp
 */
#include "Roman.h"
#include<iostream>

using namespace std;

int main()
{
  Roman rom1("MCXIV");
  Roman rom2("CCCLIX");
  Roman rom3("MDCLXVI");
  Roman rom4("CD");

  cout<<rom1.getNumeral()<<" is "<<rom1.getInteger()<<endl;
  cout<<rom2.getNumeral()<<" is "<<rom2.getInteger()<<endl;
  cout<<rom3.getNumeral()<<" is "<<rom3.getInteger()<<endl;
  cout<<rom4.getNumeral()<<" is "<<rom4.getInteger()<<endl;

  return 0;
}
