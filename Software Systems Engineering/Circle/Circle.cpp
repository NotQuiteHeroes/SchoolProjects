#include "Circle.h"
#include <cmath>
#include <iostream>
#define PI 3.1415926535897

Circle::Circle(double centerX, double centerY, double _radius)
{
        x = centerX;
        y = centerY;
        radius = _radius;
        calculateArea();
        calculateCircumference();
}

void Circle::setRadius(double newRadius)
{
        radius = newRadius;
}

double Circle::getRadius()
{
        return radius;
}

void Circle::calculateArea()
{
        area = PI*std::pow(radius, 2);
}

double Circle::getArea()
{
        return area;
}

void Circle::calculateCircumference()
{
        circumference = 2 * PI * radius;
}

double Circle::getCircumference()
{
        return circumference;
}

void Circle::printCircle()
{
        std::cout<<"Circle has center ";
        printCoords();
        std::cout<<" with a radius of "<<radius;
        std::cout<<", a circumference of "<<circumference;
        std::cout<<", and an area of "<<area<<std::endl;
}
