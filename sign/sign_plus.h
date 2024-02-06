#ifndef SIGN_PLUS_H
#define SIGN_PLUS_H

#include "sign_base.h"

class SignPlus : public Sign
{

public:
    SignPlus();
    
    double getResult(double left, double right) override;
};


#endif /* end of include guard: SIGN_PLUS_H */
