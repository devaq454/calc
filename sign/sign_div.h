#ifndef SIGN_DIV_H
#define SIGN_DIV_H

#include "sign_base.h"

class SignDiv : public Sign
{

public:
    SignDiv();
    
    double getResult(double left, double right) override;
};

#endif /* end of include guard: SIGN_DIV_H */
