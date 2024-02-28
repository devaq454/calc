#include <cmath>
#include "function_sqrt.h"

FunctionSqrt::FunctionSqrt()
    : Function("sqrt") {}

double FunctionSqrt::getResult(double value)
{
    return std::sqrt(value);
}
