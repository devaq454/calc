#include "sign_div.h"

SignDiv::SignDiv()
    : Sign("/") {}

double SignDiv::getResult(double left, double right) 
{
    return left / right;
}
