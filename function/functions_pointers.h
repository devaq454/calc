#ifndef FUNCTIONS_POINTERS_H
#define FUNCTIONS_POINTERS_H

#include <memory>
#include <string>
#include <unordered_map>
#include "function_base.h"

class FunctionPointers
{
private:
    static std::unordered_map<std::string, std::shared_ptr<Function>> functionSharedPtrs;
public:
    FunctionPointers() = delete;

    static std::shared_ptr<Function> getFunctionPtr(std::string function);
};

#endif /* end of include guard: FUNCTIONS_POINTERS_H */
