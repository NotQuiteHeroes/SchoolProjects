/**
 * Paige Eckstein
 * Software Systems Engineering
 *
 * Test file for Point and Line classes
 * Requires 'Line.h'
 * and 'Point.h'
 */
#include "Line.h"
#include <iostream>
using namespace std;

int main()
{
        //create points
        Point p1(3,2);
        Point p2(7, -4);
        //print their coordinates
        cout << "--------------------"<<endl;
        cout << "Coordinates: "<<endl;
        cout << "--------------------"<<endl;

        p1.printCoords();
        p2.printCoords();
        cout << "--------------------"<<endl;
        cout << "Line Equations: "<<endl;
        cout << "--------------------"<<endl;
        //Create line using two point objects created above
        Line line(p1, p2);
        //change points coordinates
        p1.setX(5);
        p1.setY(-8);
        p2.setX(2);
        p2.setY(7);
        //print the new coordinates of each point
        cout << "--------------------"<<endl;
        cout << "Coordinates: "<<endl;
        cout << "--------------------"<<endl;
        p1.printCoords();
        p2.printCoords();
        cout << "--------------------"<<endl;
        cout << "Line Equations: "<<endl;
        cout << "--------------------"<<endl;
        //Create line with new points as coordinates
        Line line2(p1, p2);
        cout << "--------------------"<<endl;
        return 0;
}
