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
    std::cout << "input expression to calc:" << std::endl;
    while (true)
    {
        std::cout << ">>> ";
        std::getline(std::cin, expression);
        if (expression == "q") 
            return 0;
        try
        {
            Calculator calc(expression);
            auto result = calc.calculateExpression();
            std::cout << result << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "error: " << e.what() << std::endl;
        }
    }

    return 0;
}
