#include "functions_information.h"

std::unordered_set<std::string> FunctionsInformation::functions_ = {
    "sin",
    "sqrt",
};

bool FunctionsInformation::isFunction(std::string function)
{
    return functions_.count(function);
}
