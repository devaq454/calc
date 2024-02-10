#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include "calculator.h"
#include "sign/signs_pointers.h"
#include "sign/signs_information.h"
#include "function/functions_information.h"
#include "function/functions_pointers.h"

int main()
{
    // WTF w/o that lines nothing works :)
    SignsInformation::getSignPriority("+");
    SignsPointers::getSignSharedPtr("+");
    FunctionPointers::getFunctionPtr("sin");
    FunctionsInformation::isFunction("sin");


    std::string expression;
    std::cout << "input expression to calc: ";
    std::getline(std::cin, expression);
    std::cout << std::endl;
    Calculator calc(expression);
    std::cout << "the result of expression: " << expression<< " = " << calc.calculateExpression() << std::endl;
    return 0;
}
