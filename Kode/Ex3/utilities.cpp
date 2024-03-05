#include "utilities.h"
#include "std_lib_facilities.h"

double randomWithLimits(double lowerLimit, double upperLimit)
{
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> distribution(lowerLimit, upperLimit);
    return distribution(generator);
}