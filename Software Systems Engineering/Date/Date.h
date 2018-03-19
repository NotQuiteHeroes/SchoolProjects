/**
 * Paige Eckstein
 * Software Systems Engineering
 * Date Class
 *
 * Each object of Date class will accept a date in the format
 * mm-dd-yyyy (or m-d-yy, or m/d/yy, or mm/dd/yyyy). It will
 * then, considering leap years, give the day of the year.
 * If given an invalid date (month greater than 12, day greater than 31, etc.)
 * then it will prompt user to re-enter a valid date.
 * If yyyy is shortened to yy, program will pad front with '20'.
 *
 * Example Input:
 * 12/25/1992 //leap year, output = 360
 * 12/25/05 //non-leap year, output = 359
 * 1-1-09 //output = 1
 *
 * Tested with DateTest.cpp
 */
#ifndef __MY_DATE__
#define __MY_DATE__
#include <string>
#include <regex>

class Date
{
private:
std::string numericalDate;
int month, day, year, dayOfYear;
static const int months[12];
static const std::regex validDate;

bool validateDate(std::string date);
std::string padDate(std::string date);
bool checkLeap();
void determineDay();
void determineYear();
void determineMonth();
void printResults();
void calculate();

public:
Date(std::string p_numericalDate);
};

#endif //__DATE__
