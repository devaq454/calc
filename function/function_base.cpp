#include "function_base.h"

FunctionBase::FunctionBase(std::string func)
    : strFunction_{std::move(func)} {}

std::string FunctionBase::getStrFunction()
{
    return strFunction_;
}
