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
#ifndef __ROMAN__
#define __ROMAN__
#include<string>

class Roman
{
private:
  std::string romanNumeral;
  int romanInteger;

  int getConversion(char romanChar);
  void convertNumeral();
public:
  Roman(std::string pRomanNumeral);

  std::string getNumeral();
  int getInteger();
};

#endif //__ROMAN__
