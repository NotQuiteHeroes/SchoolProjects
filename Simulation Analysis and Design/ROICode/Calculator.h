/**
 * Paige Eckstein
 *
 * Calculator class
 * acts as backend for ROI.cpp
 * Calculates ROI for given number of years, initial investment,
 * desired return, and standard deviation.
 * Also runs calculation given number of times (number of simulations)
 * and displays mean and median of final results
 *
 * Used in conjunction with:
 * ROI.cpp
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
#ifndef __CALCULATOR__
#define __CALCULATOR__

#include <vector>

class Calculator
{
public:
double getProbability();
long double normInv(double initialInvestment, double standardDeviation);
void calculateYearlyROI(int initialInvestment, std::vector<long double> &returnEachYear, std::vector<long double> &endValueEachYear, double desiredReturn, double standardDeviation, int years);
void runSimulation(int initialInvestment, std::vector<long double> &endValueEachSim, int years, double desiredReturn, double standardDeviation, int numOfSims);
void calculateMeanAndMedian(std::vector<long double> endValueEachSim, int numOfSims, long double &mean, long double &median);
};

#endif //__CALCULATOR__
