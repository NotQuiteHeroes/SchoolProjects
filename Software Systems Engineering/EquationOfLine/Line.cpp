/**
 * Paige Eckstein
 * Software Systems Engineering
 *
 * Line class acts as container for a single line
 * constructor requires two point objects, with x,y coordinates in integer form
 * Will calculate slope and y-intercept based on two points
 * Will print slope-intercept form of line, as well as standard format of line
 * Has methods to print fractions (as is standard) rather than decimal forms
 *
 * Requires Point.h
 *
 */

#include "Line.h"
#include <iostream>
#include <cmath>      //abs
#include <algorithm>  //min

/**
 * [Line::Line Line constructor. Requires two Point objects that contain
 * x and y coordinates in integer form]
 * @param p1 [First Point object]
 * @param p2 [Second Point object]
 */
Line::Line(Point p1, Point p2)
{
        //get x and y coordinates of each Point
        x1 = p1.getX();
        x2 = p2.getX();
        y1 = p1.getY();
        y2 = p2.getY();
        //calculate slope (m)
        findSlope();
        //calculate y-intercept (b)
        findIntercept();
        //find a, b, and c for Ax + By = C form
        findABC();
        //print equation of line in slope-intercept form
        // y = mx + b
        printSlopeInterceptForm();
        //print equation of line in standard form
        // Ax + By = C
        printStandardForm();
}

/**
 * [Line::findSlope Calculates slope of a line (m), using two Points x and y
 * coordinates to work with]
 */
void Line::findSlope()
{
        //numerator of slope
        slopeNum = y2-y1;
        //denominator of slope
        slopeDenom = x2-x1;
        //simplify fraction if possible
        simplify(slopeNum, slopeDenom);
}

/**
 * [Line::findIntercept Calculates y-intercept of a line (b), using one point's
 * x and y coordinates]
 */
void Line::findIntercept()
{
        //slope numerator
        bSlopeNum = slopeNum*x1;
        //slope denominator
        bSlopeDenom = slopeDenom*1;
        //multiply by denominator to get common denominator for fractional math
        int temp = y1 * bSlopeDenom;
        //now that we have a common denominator, we can simply subtract the
        //slope numerator
        bSlopeNum = temp - bSlopeNum;
        //simplify if possible
        simplify(bSlopeNum, bSlopeDenom);
}

/**
 * [Line::findABC Calculate A, B, and C values for form Ax + By = C, using
 * two point's x and y coordinates]
 */
void Line::findABC()
{
        //A
        a = y1-y2;
        //B
        b = x2-x1;
        //C
        c = (x1-x2)*y1 + (y2-y1)*x1;
        //do not want negative A value, so multiply A and B by negative one
        //if A is negative
        if(a < 0)
        {
                a *= -1;
                b *= -1;
        }
}

/**
 * [Line::simplify Simplify a fraction, given an integer numerator and integer
 * denominator]
 * @param num   [description]
 * @param denom [description]
 */
void Line::simplify(int &num, int &denom)
{
        //common divisor start at 1
        int commonDiv = 1;
        //i < the lesser of the two values (absolute value of numerator, and
        //absolute value of denominator)
        for(int i = 2; i <=std::min(abs(num), abs(denom)); i++)
        {
                //if numerator and denominator are divisible by the same number
                if(num % i == 0 && denom % i == 0)
                {
                        //then that number is a common disivor of both
                        commonDiv = i;
                }
        }
        //divide both numerator and denominator by common divisor
        num /= commonDiv;
        denom /= commonDiv;
}

/**
 * [Line::printSlopeInterceptForm Prints equation of line in format:
 *  y = mx + b]
 */
void Line::printSlopeInterceptForm()
{
        //if the denominator of both the slope (m) and y-intercept (b) are 1,
        //then we don't need to print them out (because x/1 = x)
        if(abs(slopeDenom) == 1 && abs(bSlopeDenom) == 1)
        {
                //if the denominator is a negative one, and the numerator is
                //positive, then we need to make sure the negativity stays with
                //the numerator, so multiply by -1
                if(slopeDenom < 0 && slopeNum > 0)
                {
                        slopeNum *= -1;
                }
                //if the denominator is a negative one, and the numerator is
                //positive, then we need to make sure the negativity stays
                //with the numerator, so we multiply by -1
                if(bSlopeDenom < 0 && bSlopeNum > 0)
                {
                        bSlopeNum *= -1;
                }
                //print line in form y = mx + b
                std::cout<<"y = "<<slopeNum<<"x + "<<bSlopeNum<<std::endl;
        }
        //else if the denominator of just the slope (m) is 1, then we don't
        //need to print it (because x/1 = x)
        else if(abs(slopeDenom) == 1)
        {
                //if the denominator is a negative one, and the numerator is
                //positive, then we need to make sure the negativity stays with
                //the numerator, so multiply by -1
                if(slopeDenom < 0 && slopeNum > 0)
                {
                        slopeNum *= -1;
                }
                //print in form y = mx + b
                std::cout<<"y = "<<slopeNum<<"x + "<<bSlopeNum<<"/"<<bSlopeDenom<<std::endl;
        }
        //else if just the denominator of the y-intercept is 1, then we don't
        //need to print it (because x/1 = x)
        else if(abs(bSlopeDenom) == 1)
        {
                //if the denominator is a negative one, and the numerator is
                //positive, then we need to make sure the negativity stays
                //with the numerator, so we multiply by -1
                if(bSlopeDenom < 0 && bSlopeNum > 0)
                {
                        bSlopeNum *= -1;
                }
                //print in form y = mx + b
                std::cout<<"y = "<<slopeNum<<"/"<<slopeDenom<<"x + "<<bSlopeNum<<std::endl;
        }
        //If the denominators of both the slope and y-intercept are greater
        //than one, then print in standard form y = mx + b
        else
        {
                std::cout<<"y = "<<slopeNum<<"/"<<slopeDenom<<"x + "<<bSlopeNum<<"/"<<bSlopeDenom<<std::endl;
        }
}

/**
 * [Line::printStandardForm Print equation of line in standard form:
 * Ax + By = C]
 */
void Line::printStandardForm()
{
        std::cout<<a<<"x + "<<b<<"y = "<<c<<std::endl;
}
