#include "signs_pointers.h"
#include "sign_plus.h"
#include "sign_minus.h"
#include "sign_mul.h"
#include "sign_div.h"
#include "sign_pow.h"

std::unordered_map<std::string, std::shared_ptr<Sign>> 
    SignsPointers::signSharedPtrs = {
    {"+", std::make_shared<SignPlus>()},
    {"-", std::make_shared<SignMinus>()},
    {"*", std::make_shared<SignMul>()},
    {"/", std::make_shared<SignDiv>()},
    {"**", std::make_shared<SignPow>()},
};

std::shared_ptr<Sign> SignsPointers::getSignSharedPtr(std::string sign)
{
    return signSharedPtrs.at(sign);
}
