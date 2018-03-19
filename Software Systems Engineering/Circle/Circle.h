#ifndef __CIRCLE__
#define __CIRCLE__

#include "Point.h"

class Circle : public Point
{
private:
double radius;
double area;
double circumference;
public:
Circle(double centerX, double centerY, double _radius);
void setRadius(double newRadius);
double getRadius();
void calculateArea();
double getArea();
void calculateCircumference();
double getCircumference();
void printCircle();
};
#endif
