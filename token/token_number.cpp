#include "token_number.h"
#include "../sign/sign_plus.h"

TokenNumber::TokenNumber(std::string number)
    : Token(number), number_{std::stod(number)}
{
    setIsNumber(true);
}

TokenNumber::TokenNumber(double number)
    : Token(std::to_string(number)), number_(number)
{
    setIsNumber(true);
}

double TokenNumber::getNumber() 
{
    return number_;
}

void TokenNumber::setNumber(double number)
{
    number_ = number;
}

// TODO idk what's here the best decision
bool TokenNumber::isLeftBracket()
{
    throw std::runtime_error("try to get bracket from token-number");
    // fictive
    return false;
}

std::shared_ptr<Sign> TokenNumber::getSign()
{
    throw std::runtime_error("try to get sign from token-number");
    // fictive
    return std::make_shared<SignPlus>();
}
