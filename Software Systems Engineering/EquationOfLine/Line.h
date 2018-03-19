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
#ifndef __ONE_LINE__
#define __ONE_LINE__

#include "Point.h"
class Line
{
private:
int x1, x2, y1, y2;
int bSlopeNum, bSlopeDenom;
int slopeNum, slopeDenom;
int a, b, c;
void findSlope();
void findIntercept();
void findABC();
void simplify(int &num, int &denom);
public:
Line(Point p1, Point p2);
void printSlopeInterceptForm();
void printStandardForm();
};
#endif //__LINE__
