#include "token_bracket.h"
#include "../sign/sign_plus.h"

TokenBracket::TokenBracket(std::string bracket) 
    : Token(bracket), isLeftBracket_{bracket == "("}
{
    if (bracket != "(" && bracket != ")")
    {
        throw std::runtime_error("invalid symbol for bracket initialization: {"
                                 + bracket + "}");
    }
    setIsBracket(true);
}

TokenBracket::TokenBracket(bool isLeft)
    : Token(isLeft ? "(" : ")"), isLeftBracket_{isLeft}
{
    setIsBracket(true);
}

bool TokenBracket::isLeftBracket()
{
    return isLeftBracket_;
}

// TODO idk what's here the best decision
std::shared_ptr<Sign> TokenBracket::getSign()
{
    throw std::runtime_error("try to get sign from token-bracket");
    // fictive
    return std::make_shared<SignPlus>();
}

double TokenBracket::getNumber()
{
    throw std::runtime_error("try to get number from token-bracket");
    // fictive
    return .0;
}
