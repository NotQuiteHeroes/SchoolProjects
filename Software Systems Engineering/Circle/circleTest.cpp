#include "Circle.h"
#include <iostream>

using namespace std;

int main()
{
        Circle circle1(4, 7, 5);
        cout << "First circle: "<<endl;
        cout << "----------------------"<<endl;
        circle1.printCircle();
        Circle circle2(-2, 0, 11);
        cout << "----------------------"<<endl;
        cout << "Second circle: "<<endl;
        cout << "----------------------"<<endl;
        circle2.printCircle();
        cout << "----------------------"<<endl;
}
