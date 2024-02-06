#include "token_sign.h"
#include "../sign/signs_pointers.h"

TokenSign::TokenSign(std::string sign)
    : Token(sign), sign_{SignsPointers::getSignSharedPtr(sign)}
{
    setIsSign(true);
}

std::shared_ptr<Sign> TokenSign::getSign()
{
    return sign_;
}

// TODO idk what's here the best decision :(
double TokenSign::getNumber()
{
    throw std::runtime_error("try to get number from token-sign");
    // fictive
    return -1;
}

bool TokenSign::isLeftBracket()
{
    throw std::runtime_error("try to get bracket from token-sign");
    // fictive
    return false;
}
