#ifndef SIGN_POW_H
#define SIGN_POW_H

#include "sign_base.h"


class SignPow : public Sign
{
public:
    SignPow();

    double getResult(double left, double right) override;
};


#endif /* end of include guard: SIGN_POW_H */
