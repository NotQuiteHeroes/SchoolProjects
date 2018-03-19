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

/**
 * [Roman::Roman Constructor - initializes romanNumeral with given
 * input and romanInteger to 0. Calls convertNumeral to begin
 * conversion process.]
 * @param pRomanNumeral [string of standard Roman Numeral. Assumes
 * Roman Numeral is in correct format.]
 */
Roman::Roman(std::string pRomanNumeral)
{
  romanNumeral = pRomanNumeral;
  romanInteger = 0;
  convertNumeral();
}

/**
 * [Roman::getConversion returns integer conversion of provided character in
 * Roman Numeral format.]
 * @param  romanChar [single Roman Numeral to convert]
 * @return           [integer form of single Roman Numeral character]
 */
int Roman::getConversion(char romanChar)
{
  if(romanChar == 'I')
    return 1;
  else if(romanChar == 'V')
    return 5;
  else if(romanChar == 'X')
    return 10;
  else if(romanChar == 'L')
    return 50;
  else if(romanChar == 'C')
    return 100;
  else if(romanChar == 'D')
    return 500;
  else if(romanChar == 'M')
    return 1000;
}

/**
 * [Roman::convertNumeral Breaks Roman Numeral string into individual
 * characters and converts them one by one. Takes into account that
 * a lesser valued numeral before a greater valued numeral means to
 * subtract, rather than add. Stores resulting conversion in romanInteger]
 */
void Roman::convertNumeral()
{
  int length = romanNumeral.length();

  for(int i = 0; i < length; i++)
  {
    //current single numeral character being converted
    int current = getConversion(romanNumeral.at(i));

    if(i+1 < length)
    {
      //single numeral character sequentially after current
      int next = getConversion(romanNumeral.at(i+1));

      //if the current numeral is greater than the one following it
      if(current >= next)
      {
        romanInteger += current;
      }
      //if the current numeral is less than the one following it
      else
      {
        romanInteger+=next-current;
        i++;
      }
    }
    //last numeral character in string does not effect decision to add or
    //subtract, so simply add current to romanInteger
    else
    {
      romanInteger += current;
      i++;
    }
  }
}

/**
 * [Roman::getNumeral returns string version of Roman Numeral given upon
 * initialization of object]
 * @return [string version of Roman Numeral]
 */
std::string Roman::getNumeral()
{
  return romanNumeral;
}

/**
 * [Roman::getInteger returns integer version of Roman Numeral, which is
 * obtained through conversion of the string form given at initialization]
 * @return [integer version of Roman Numeral]
 */
int Roman::getInteger()
{
  return romanInteger;
}
