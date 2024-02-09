#include "functions_pointers.h"
#include "function_sin.h"

std::unordered_map<std::string, std::shared_ptr<Function>>
    FunctionPointers::functionSharedPtrs = 
{
    {"sin", std::make_shared<FunctionSin>()},
};

std::shared_ptr<Function> FunctionPointers::getFunctionPtr(std::string function)
{
    return functionSharedPtrs.at(function);
}
