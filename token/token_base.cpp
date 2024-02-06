#include "token_base.h"

Token::Token(std::string value)
    : value_{std::move(value)}, isSign_{false}, isNumber_{false}, isBracket_{false} {}

std::string Token::getValue() { return value_; };

void Token::setValue(std::string value)
{
    value_ = std::move(value);
}

bool Token::isSign()
{
    return isSign_;
}
bool Token::isNumber()
{
    return isNumber_;
}
bool Token::isBracket()
{
    return isBracket_;
}

void Token::setIsSign(bool isSign)
{
    isSign_ = isSign;
}
void Token::setIsNumber(bool isNumber)
{
    isNumber_ = isNumber;
}
void Token::setIsBracket(bool isBracket)
{
    isBracket_ = isBracket;
}

