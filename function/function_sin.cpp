#include <cmath>
#include "function_sin.h"

FunctionSin::FunctionSin()
    : Function("sin") {}


double FunctionSin::getResult(double value)
{
    return std::sin(value);
}
