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
#include "Date.h"
#include <iostream>

//number of completed days in a year by beginning of each month
const int Date::months[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

//regex pattern used to validate date format given in form mm/dd/yyyy or mm-dd-yyyy
// ^                            match beginning of line
// (0[1-9]|1[012])              match month as 01-09 or 10-12
// ([-/])                       match - or / between numbers
// (0[1-9]|[12][0-9]|3[01])     match day as 01-09, 10-19, 20-29, or 30-31
// ([-/])                       match - or / between numbers
// (19|20)\\d\\d                match valid year as anything between 1900-2099
// $                            end of target
const std::regex Date::validDate("^(0[1-9]|1[012])([-/])(0[1-9]|[12][0-9]|3[01])([-/])(19|20)\\d\\d$");

/**
 * [Date::Date Constructor requiring date]
 * @param p_numericalDate [date in string form to perform calculations upon]
 */
Date::Date(std::string p_numericalDate)
{
        //pad date if necessary to get to form mm-dd-yyyy
        std::string date = padDate(p_numericalDate);
        //if valid date (month and days fall within allowed range)
        if(validateDate(date))
        {
                //set string date to field numericalDate and begin calculations
                numericalDate = date;
                calculate();
        }
        //if not valid date
        else
        {
                //repeatedly prompt user until valid date is given
                while(!validateDate(date))
                {
                        std::cout<<"Enter a valid date."<<std::endl;
                        std::cin>>date;
                        date = padDate(date);
                }
                //set string date  to field numericalDate and begin calculations
                numericalDate = date;
                calculate();
        }
}

/**
 * [Date::validateDate Checks if given date is valid, meaning the month
 * and day fall within the appropriate range (1-12, 1-31)]
 * Returns true if valid date, false otherwise
 * @param  date [String to check if valid date]
 * @return      [true if valid date, false otherwise]
 */
bool Date::validateDate(std::string date)
{
        //use regex pattern validDate to determine if input is a valid date
        if(std::regex_match(date, validDate))
        {
                return true;
        }
        return false;
}

/**
 * [Date::padDate Adds leading 0s to day or month if format m-d-yyyy
 * and adds leading '20' to any year in format yy.]
 * @param  date [string date to pad out if in shortened form]
 * @return      [string date in form mm-dd-yyyy]
 */
std::string Date::padDate(std::string date)
{
        //full form mm-dd-yyyy = length of 10. Less than that requires padding
        if(date.length() < 10)
        {
                //if month is shortened
                if(date[2] != '-' && date[2] != '/' && date[2])
                {
                        date = '0'+date;
                }
                //if day is shortened
                if(date[5] != '-' && date[5] != '/')
                {
                        date = date.substr(0, 3) + '0' + date.substr(3);
                }
                //if year is shortened (defaults to 20xx)
                if(date.substr(6).length() < 4)
                {
                        date = date.substr(0, 6) + "20" + date.substr(6);
                }
        }
        return date;
}

/**
 * [Date::checkLeap Checks if year is a leap year]
 * @return [true if leap year, false if not]
 */
bool Date::checkLeap()
{
        //if year is divisible by 4 and not by 100.
        //if year is divisible by 100 and by 400
        //then it is a leap year
        return ((year % 400) == 0) || (((year % 100) != 0) && ((year % 4) == 0));
}

/**
 * [Date::determineDay get integer form of day from full date string]
 */
void Date::determineDay()
{
        day = std::stoi(numericalDate.substr(3, 2));
}

/**
 * [Date::determineMonth get integer form of month from full date string]
 */
void Date::determineMonth()
{
        month = std::stoi(numericalDate.substr(0, 2));
}

/**
 * [Date::determineYear get integer form of year from full date string]
 */
void Date::determineYear()
{
        year = std::stoi(numericalDate.substr(6));
}

/**
 * [Date::printResults Calculates day of year by adding days
 * that have occurred up until the given month + the given day.
 * Checks if it is a leap year, and if so add one to the day of year.
 * Print day of year]
 */
void Date::printResults()
{
        int date = months[month-1] + day;
        if(checkLeap() && month > 2)
        {
                date++;
        }
        std::cout<<date<<std::endl;
}

/**
 * [Date::calculate Sets integer forms of day, month, and year then
 * calculates day of year and prints the result]
 */
void Date::calculate()
{
        determineDay();
        determineMonth();
        determineYear();
        printResults();
}
