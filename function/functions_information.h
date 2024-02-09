#include <unordered_set>
#include "function_base.h"

class FunctionsInformation
{
private:
    static std::unordered_set<std::string> functions_;

public:
    FunctionsInformation() = delete;

    static bool isFunction(std::string function);
};
