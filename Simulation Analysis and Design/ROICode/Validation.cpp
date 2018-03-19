/**
 * Paige Eckstein
 *
 * Validation class
 * Used to validate non-default values given by user in ROI.cpp
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
 */
#include "Validation.h"
#include <iostream>
/**
 * [validateYears Confirm year is a positive integer]
 * @param  years [Year value to validate]
 */
void Validation::validateYears(int &years)
{
        while(years < 0)
        {
                std::cout<<"Enter a valid year amount greater than 0: "<<std::endl;
                std::cin>>years;
        }
}

/**
 * [validateNumOfSims Confirm number of simulations is > 0]
 * @param  numOfSims [Number of simulations to validate]
 */
void Validation::validateNumOfSims(int &numOfSims)
{
        while(numOfSims < 0)
        {
                std::cout<<"Enter a valid number of simulations greater than -1: "<<std::endl;
                std::cin>>numOfSims;
        }
}

/**
 * [validateDesiredReturn validate desired return is between 1 and 0]
 * @param  desiredReturn [Desired Return value to validate]
 */
void Validation::validateDesiredReturn(double &desiredReturn)
{
        //if in percent form, get decimal form
        if(desiredReturn >= 1)
        {
                desiredReturn/=100;
        }
        while(desiredReturn > 1 || desiredReturn < 0)
        {
                std::cout<<"Enter a valid desired return: "<<std::endl;
                std::cin>>desiredReturn;
        }
}

/**
 * [validateStdDev Validate standard deviation is between 1 and 0]
 * @param  stdDev [standard deviation to validate]
 */
void Validation::validateStdDev(double &stdDev)
{
        //if in percent form, get decimal form
        if(stdDev >= 1)
        {
                stdDev/=100;
        }
        while(stdDev > 1 || stdDev < 0)
        {
                std::cout<<"Enter a valid standard deviation: "<<std::endl;
                std::cin>>stdDev;
        }
}

/**
 * [validateInvestment validate initial investment is > 0]
 * @param  investment [investment to validate]
 */
void Validation::validateInvestment(long double &investment)
{
        while(investment < 0)
        {
                std::cout<<"Enter a valid investment greater than -1: "<<std::endl;
                std::cin>>investment;
        }
}
