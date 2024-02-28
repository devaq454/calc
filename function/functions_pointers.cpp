#include "functions_pointers.h"
#include "function_sin.h"
#include "function_sqrt.h"

std::unordered_map<std::string, std::shared_ptr<Function>>
    FunctionPointers::functionSharedPtrs = 
{
    {"sin", std::make_shared<FunctionSin>()},
    {"sqrt", std::make_shared<FunctionSqrt>()},
};

std::shared_ptr<Function> FunctionPointers::getFunctionPtr(std::string function)
{
    return functionSharedPtrs.at(function);
}
