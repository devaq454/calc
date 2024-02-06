#include "sign_minus.h"

SignMinus::SignMinus()
    : Sign("-") {}

double SignMinus::getResult(double left, double right) 
{
    return left - right;
}
