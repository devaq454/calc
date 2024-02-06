#ifndef SIGN_MINUS_H
#define SIGN_MINUS_H

#include "sign_base.h"

class SignMinus : public Sign
{

public:
    SignMinus();
    
    double getResult(double left, double right) override;
};


#endif /* end of include guard: SIGN_MINUS_H */
