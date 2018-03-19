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
 * Requires Point.h
 *
 */
#include "Point.h"
#include <iostream>

/**
 * [Point::Point Point constructor. Requires x and y coordinates to set
 * private fields.]
 * @param _x [x coordinate in integer form]
 * @param _y [y coordinate in integer form]
 */
Point::Point(int _x, int _y)
{
        x = _x;
        y = _y;
}

Point::Point()
{
}
/**
 * [Point::getX getter for x coordinate]
 * @return [x in integer form]
 */
int Point::getX()
{
        return x;
}

/**
 * [Point::getY getter for y coordinate]
 * @return [y in integer form]
 */
int Point::getY()
{
        return y;
}

/**
 * [Point::setX setter for x coordinate]
 * @param _x [new x coordinate to set interval field x, integer]
 */
void Point::setX(int _x)
{
        x = _x;
}

/**
 * [Point::setY setter for y coordinate]
 * @param _y [new y coordinate to set interval field y, integer]
 */
void Point::setY(int _y)
{
        y = _y;
}

/**
 * [Point::printCoords prints coordinate pair in form (x, y)]
 */
void Point::printCoords()
{
        std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}
