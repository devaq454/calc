#include <cmath>
#include "function_sin.h"

FunctionSin::FunctionSin()
    : Function("sin") {}


double FunctionSin::getResult(double value)
{
    return std::sin(value * 3.141592653589793238463 / 180);
}
