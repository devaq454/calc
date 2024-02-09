#ifndef FUNCTION_BASE_H
#define FUNCTION_BASE_H

#include <string>

class FunctionBase
{
private:
    std::string strFunction_;

public:
    FunctionBase(std::string func);

    std::string getStrFunction();

    virtual double getResult(double value) = 0;
};

#endif /* end of include guard: FUNCTION_BASE_H */
