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
#ifndef __VALIDATION__
#define __VALIDATION__

class Validation
{
public:
void validateYears(int &years);
void validateNumOfSims(int &numOfSims);
void validateDesiredReturn(double &desiredReturn);
void validateStdDev(double &stdDev);
void validateInvestment(long double &investment);
};

#endif //__VALIDATION__
