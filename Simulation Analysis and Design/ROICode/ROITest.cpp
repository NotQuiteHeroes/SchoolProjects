/**
 * Paige Eckstein
 *
 * ROI class
 * acts as frontend for simplification of use with ROITest.cpp
 * Calculates ROI for given number of years, initial investment,
 * desired return, and standard deviation.
 * Also runs calculation given number of times (number of simulations)
 * and displays mean and median of final results
 *
 * Has multiple constructors for modifications:
 * Default constructor sets:
 * years = 7
 * initial investment = 150,000
 * number of simulations = 100
 * desired return 10%
 * standard deviation .15
 *
 * Nondefault constructors allow the user to set all values themselves,
 * or set all values and use default standard deviation
 *
 * Requires:
 * Calculator.h/.cpp
 * Validation.h/.cpp
 *
 * Tested with:
 * ROITest.cpp
 *
 * Compilation:
 * g++ Calculator.cpp Validation.cpp ROI.cpp ROITest.cpp
 *
 * Norm.Inv function converted to C++ from Javascript version found
 * at kmpm's github:
 * https://gist.github.com/kmpm/1211922/6b7fcd0155b23c3dc71e6f4969f2c48785371292
 */
#include "ROI.h"
#include <iostream>

using namespace std;

int main()
{

        ROI roi;
        ROI roi2(80000, 10, 100, 15);
        ROI roi3(12000, 5, 50, 10, 20);
        return 0;
}
