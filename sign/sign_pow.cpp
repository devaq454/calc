#include "sign_pow.h"
#include <cmath>

SignPow::SignPow()
    : Sign("**") {}

double SignPow::getResult(double left, double right)
{
    return std::pow(left, right);
}
