#ifndef SIGN_MUL_H
#define SIGN_MUL_H

#include "sign_base.h"

class SignMul : public Sign
{

public:
    SignMul();
    
    double getResult(double left, double right) override;
};

#endif /* end of include guard: SIGN_MUL_H */
