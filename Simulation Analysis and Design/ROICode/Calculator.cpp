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
#include "Calculator.h"
#include <numeric>    //accumulate
#include <algorithm>  //sort
#include <random>
#include <limits>     //infinity
#include <cmath>      //abs and log

/**
 * [getProbability Return random probability chance between 0 and 1]
 * @return [Random double between 0 and 1]
 */
double Calculator::getProbability()
{
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_real_distribution<double> distribution(0, 1);
        return (distribution(generator));
}

/**
 * [Calculator::normInv C++ implementation of NORM.INV function in excel.
 * Calculates the inverse of the Cumulative Normal Distribution function
 * for given probability, distribution mean, and standard deviation]
 * @param  desiredReturn     [Desired return rate, used as distribution mean]
 * @param  standardDeviation [Standard Deviation for Normal Distribution Function]
 * @return                   [double -Inverse of the cumulative normal distribution function]
 * Converted from JavaScript code found at kmpm's github:
 * https://gist.github.com/kmpm/1211922/6b7fcd0155b23c3dc71e6f4969f2c48785371292
 */
long double Calculator::normInv(double desiredReturn, double standardDeviation)
{
        double p = getProbability();
        if(p == 0)
        {
                return -std::numeric_limits<double>::infinity();
        }

        if(p == 1)
        {
                return std::numeric_limits<double>::infinity();
        }

        if(standardDeviation == 0)
        {
                return desiredReturn;
        }

        double q, r, val;

        q = p - 0.5;

        if(std::abs(q) <= .425)
        {
                r = .180625 - q * q;
                val =
                        q * (((((((r * 2509.0809287301226727 +
                                   33430.575583588128105) * r + 67265.770927008700853) * r +
                                 45921.953931549871457) * r + 13731.693765509461125) * r +
                               1971.5909503065514427) * r + 133.14166789178437745) * r +
                             3.387132872796366608)
                        / (((((((r * 5226.495278852854561 +
                                 28729.085735721942674) * r + 39307.89580009271061) * r +
                               21213.794301586595867) * r + 5394.1960214247511077) * r +
                             687.1870074920579083) * r + 42.313330701600911252) * r + 1);
        }
        else
        {
                if(q > 0)
                {
                        r = 1 - p;
                }
                else
                {
                        r = p;
                }

                r = std::sqrt(-std::log(r));

                if(r <= 5)
                {
                        r+=-1.6;
                        val = (((((((r * 7.7454501427834140764e-4 +
                                     .0227238449892691845833) * r + .24178072517745061177) *
                                   r + 1.27045825245236838258) * r +
                                  3.64784832476320460504) * r + 5.7694972214606914055) *
                                r + 4.6303378461565452959) * r +
                               1.42343711074968357734)
                              / (((((((r *
                                       1.05075007164441684324e-9 + 5.475938084995344946e-4) *
                                      r + .0151986665636164571966) * r +
                                     .14810397642748007459) * r + .68976733498510000455) *
                                   r + 1.6763848301838038494) * r +
                                  2.05319162663775882187) * r + 1);
                }
                else
                {
                        r += -5;
                        val = (((((((r * 2.01033439929228813265e-7 +
                                     2.71155556874348757815e-5) * r +
                                    .0012426609473880784386) * r + .026532189526576123093) *
                                  r + .29656057182850489123) * r +
                                 1.7848265399172913358) * r + 5.4637849111641143699) *
                               r + 6.6579046435011037772)
                              / (((((((r *
                                       2.04426310338993978564e-15 + 1.4215117583164458887e-7) *
                                      r + 1.8463183175100546818e-5) * r +
                                     7.868691311456132591e-4) * r + .0148753612908506148525)
                                   * r + .13692988092273580531) * r +
                                  .59983220655588793769) * r + 1);
                }

                if(q < 0.0)
                {
                        val = -val;
                }
        }
        return desiredReturn + standardDeviation * val;
}

/**
 * [Calculator::calculateYearlyROI Calculates return percentage each year,
 * as well as end value for each year.]
 * @param initialInvestment [Initial Investment at beginning of first year]
 * @param returnEachYear    [Vector to hold return percentage for each year]
 * @param endValueEachYear  [Vector to hold end value for each year]
 * @param desiredReturn     [Desired return percentage, for use with norminv]
 * @param standardDeviation [Standard deviation, for use with norminv]
 * @param years             [Number of years to calculate ROI for]
 */
void Calculator::calculateYearlyROI(int initialInvestment, std::vector<long double> &returnEachYear, std::vector<long double> &endValueEachYear, double desiredReturn, double standardDeviation, int years)
{
        long double currentROI = initialInvestment;
        long double currentReturn = 0;

        for(int i = 0; i < years; i++) {
                currentReturn = 1 + normInv(desiredReturn, standardDeviation);
                currentROI = currentROI * currentReturn;
                returnEachYear.push_back(currentReturn-1);
                endValueEachYear.push_back(currentROI);
        }

}

/**
 * [Calculator::runSimulation Runs full CalculateYearlyROI cycle for desired
 * number of simulations. Accumulates end values for each cycle and stores in vector]
 * @param initialInvestment [Initial investment at beginning of each year]
 * @param endValueEachSim   [ Vector to hold final end value for each CalculateYearlyROI cycle]
 * @param years             [number of years to calculate ROI for]
 * @param desiredReturn     [Desired return percentage, for use with norminv]
 * @param standardDeviation [Standard Deviation for use with norminv]
 * @param numOfSims         [Number of times to cycle full CalculateYearlyROI run]
 */
void Calculator::runSimulation(int initialInvestment, std::vector<long double> &endValueEachSim, int years, double desiredReturn, double standardDeviation, int numOfSims)
{
        long double currentCalculator = initialInvestment;
        std::vector<long double> yearlyCalculator;

        for(int i = 0; i < numOfSims; i++)
        {
                yearlyCalculator.clear();
                currentCalculator = initialInvestment;
                for(int i = 0; i < years; i++) {
                        currentCalculator = currentCalculator * (1+ normInv(desiredReturn, standardDeviation));
                        yearlyCalculator.push_back(currentCalculator);
                }
                endValueEachSim.push_back(yearlyCalculator.at(years-1));
        }
}

/**
 * [Calculator::calculateMeanAndMedian Calculate mean and median values
 * from endValues stored from runSimulation]
 * @param endValueEachSim [Final end value for each CalculateYearlyROI cycle]
 * @param numOfSims       [number of simulations to run]
 * @param mean            [mean value of all end values from simulation]
 * @param median          [median value of all end values from simulation]
 */
void Calculator::calculateMeanAndMedian(std::vector<long double> endValueEachSim, int numOfSims, long double &mean, long double &median)
{
        double sum = std::accumulate(endValueEachSim.begin(), endValueEachSim.end(), 0.0);
        mean = sum /numOfSims;

        std::sort(endValueEachSim.begin(), endValueEachSim.end());
        if(numOfSims % 2 == 0)
        {
                median = (endValueEachSim[numOfSims/2] + endValueEachSim[(numOfSims/2)-1])/2;
        }
        else
        {
                median = (endValueEachSim.at(numOfSims/2));
        }
}
