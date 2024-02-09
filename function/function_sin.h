#ifndef FUNCTINO_SIN_H
#define FUNCTINO_SIN_H
#include "function_base.h"

class FunctionSin : public Function
{
public:
    FunctionSin();

    double getResult(double value) override;
};


#endif /* end of include guard: FUNCTINO_SIN_H */
