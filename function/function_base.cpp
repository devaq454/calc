#include "function_base.h"

Function::Function(std::string func)
    : strFunction_{std::move(func)} {}

std::string Function::getStrFunction()
{
    return strFunction_;
}
