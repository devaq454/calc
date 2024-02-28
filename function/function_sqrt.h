#ifndef FUNCTION_SQRT_H
#define FUNCTION_SQRT_H
#include "function_base.h"

class FunctionSqrt : public Function
{
public:
    FunctionSqrt();

    double getResult(double value) override;
};


#endif /* end of include guard: FUNCTION_SQRT_H */
