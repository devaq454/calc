#include "token_function.h"
#include "../function/functions_pointers.h"
#include "../sign/sign_plus.h"

TokenFunction::TokenFunction(std::string function)
    : Token(function), function_{FunctionPointers::getFunctionPtr(function)}
{
    setIsFunction(true);
}

std::shared_ptr<Function> TokenFunction::getFunction()
{
    return function_;
}


// TODO idk what's here the best decision :(
double TokenFunction::getNumber()
{
    throw std::runtime_error("try to get number from token-function");
    // fictive
    return -1;
}

bool TokenFunction::isLeftBracket()
{
    throw std::runtime_error("try to get bracket from token-function");
    // fictive
    return false;
}

std::shared_ptr<Sign> TokenFunction::getSign()
{
    throw std::runtime_error("try to get sign from token-sign");
    return std::shared_ptr<SignPlus>();
}
