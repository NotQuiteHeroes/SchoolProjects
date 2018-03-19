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

int main()
{
        //full valid date = 1
        Date date1("01-01-2000");
        //shortened year form = 359
        Date date2("12-25-09");
        //shortened day form + leap year = 205
        Date date3("7/23/1992");
        //invalid date form
        Date date4("40-15-16");

        return 0;
}
