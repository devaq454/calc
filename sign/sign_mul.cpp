#include "sign_mul.h"

SignMul::SignMul()
    : Sign("*") {}

double SignMul::getResult(double left, double right) 
{
    return left * right;
}
