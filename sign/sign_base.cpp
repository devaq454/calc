#include "sign_base.h"
#include <iostream>
#include "signs_information.h"


Sign::Sign(std::string sign)
    : priority_{SignsInformation::getSignPriority(sign)}, strSign_{sign} {}

std::string Sign::getStrSign()
{
    return strSign_;
}

void Sign::setPriority(int priority)
{
    priority_ = priority;
}

int Sign::getPriority()
{
    return priority_;
}
