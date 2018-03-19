/**
 * Paige Eckstein
 * Software Systems Engineering
 *
 * Point class acts as container for coordinate
 * point in form (x, y)
 * Constructor takes x and y coordinate
 * Has methods for setting and retrieving each coordinate individually
 * and method for printing coordinates in pair form (x, y)
 *
 */
#ifndef __POINT__
#define __POINT__

class Point
{
private:
int x, y;
public:
Point(int _x, int _y);
int getX();
int getY();
void setX(int _x);
void setY(int _y);
void printCoords();
};
#endif //__POINT__
