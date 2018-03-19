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
#include <iomanip>

/**
 * [ROI Default constructor. Looks at ROI over 7 years
 * with initial investment of $150,000 and desired desired return
 * of 10% and standard deviation of 15%. Runs 100 simulations.]
 */
ROI::ROI()
{
        years = 7;
        numOfSims = 100;
        initialInvestment = 150000;
        endValue = 0;
        mean = 0;
        median = 0;
        desiredReturn = .10;
        standardDeviation = .15;

        calculateYearlyROI();
}

/**
 * [ROI Nondefault constructor. Requires input for initial investment,
 * years to collect return on, desired number of simulations to run,
 * and the desired return percentage.]
 * @param pInitial   [Initial investment amount]
 * @param pYears     [Number of years to collect return on]
 * @param pNumOfSims [Number of simulations to run]
 * @param pDesired   [Desired return]
 */
ROI::ROI(long double pInitial, int pYears, int pNumOfSims, double pDesired)
{
        validate.validateYears(pYears);
        years = pYears;
        validate.validateNumOfSims(pNumOfSims);
        numOfSims = pNumOfSims;
        validate.validateInvestment(pInitial);
        initialInvestment = pInitial;
        endValue = 0;
        mean = 0;
        median = 0;
        validate.validateDesiredReturn(pDesired);
        desiredReturn = pDesired;
        standardDeviation = .10;

        calculateYearlyROI();
}

/**
 * [ROI Non default constructor. Requires input for initial investment,
 * years to collect return on, desired number of simulations to run, desired
 * return, and standard deviation value.]
 * @param pInitial     [initial investment]
 * @param pYears       [years to collect return on]
 * @param pNumOfSims   [number of simulations]
 * @param pDesired     [desired return]
 * @param pStandardDev [standard deviation]
 */
ROI::ROI(long double pInitial, int pYears, int pNumOfSims, double pDesired, double pStandardDev)
{
        validate.validateYears(pYears);
        years = pYears;
        validate.validateNumOfSims(pNumOfSims);
        numOfSims = pNumOfSims;
        validate.validateInvestment(pInitial);
        initialInvestment = pInitial;
        endValue = 0;
        mean = 0;
        median = 0;
        validate.validateDesiredReturn(pDesired);
        desiredReturn = pDesired;
        validate.validateStdDev(pStandardDev);
        standardDeviation = pStandardDev;

        calculateYearlyROI();
}

/**
 * [ROI::calculateYearlyROI Calculates return percentage for each year, as well
 * as end value for each year. Sets final endValue for entire run.]
 */
void ROI::calculateYearlyROI()
{
        calc.calculateYearlyROI(initialInvestment, returnEachYear, endValueEachYear, desiredReturn, standardDeviation, years);
        endValue = endValueEachYear.at(years-1);
        runSimulation();
        displayResults();

}

/**
 * [ROI::runSimulation Runs simulation for given number of times - Cycles
 * through CalculateYearlyROI and collects final end values in vector]
 */
void ROI::runSimulation()
{
        calc.runSimulation(initialInvestment, endValueEachSim, years, desiredReturn, standardDeviation, numOfSims);
        calculateMeanAndMedian();
}

/**
 * [ROI::calculateMeanAndMedian calculates mean and median values for simulation
 * results]
 */
void ROI::calculateMeanAndMedian()
{
        calc.calculateMeanAndMedian(endValueEachSim, numOfSims, mean, median);
}

/**
 * [ROI::displayResults prints final resultsn]
 */
void ROI::displayResults()
{
        std::cout<<std::fixed<<std::setprecision(2);
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<"\tYearly results"<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<"Initial Investment: $"<<initialInvestment<<std::endl;
        std::cout<<"Final amount: $"<<endValue<<std::endl;
        std::cout<<"Desired Return: "<<desiredReturn * 100 <<"%"<<std::endl;
        std::cout<<"Standard Deviation: "<<standardDeviation<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
        std::cout<<"Year\tReturn\t\tEnd Value"<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
        for(int i = 0; i < years; i++)
        {
                std::cout<<i+1<<".\t"<<returnEachYear.at(i)*100<<"%\t\t$"<<endValueEachYear.at(i)<<std::endl;
        }
        std::cout<<"----------------------------------------"<<std::endl;
        std::cout<<"\tSimulation results"<<std::endl;
        std::cout<<"----------------------------------------"<<std::endl;
        std::cout<<"Number of simulations ran: "<<numOfSims<<std::endl;
        std::cout<<"Mean result of simulations: $"<<mean<<std::endl;
        std::cout<<"Median result of simulations: $"<<mean<<std::endl;
        std::cout<<"---------------------------------------"<<std::endl;
}
