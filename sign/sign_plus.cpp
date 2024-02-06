#include "sign_plus.h"

SignPlus::SignPlus()
    : Sign("+") {}

double SignPlus::getResult(double left, double right) 
{
    return left + right;
}
