#ifndef SIGN_BASE_H
#define SIGN_BASE_H

#include <iostream>

class Sign
{
private:
    std::string strSign_;
    int priority_;

public:
    Sign(std::string sign);

    std::string getStrSign();

    void setPriority(int priority);
    int getPriority();


    virtual double getResult(double left, double right) = 0;
};


#endif /* end of include guard: SIGN_BASE_H */
