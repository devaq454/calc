#ifndef TOKEN_BRACKET_H
#define TOKEN_BRACKET_H

#include "token_base.h"

class TokenBracket : public Token
{
private:
    bool isLeftBracket_;

public:
    // for "(" or ")"
    TokenBracket(std::string bracket);
    // for 1 = "("; 0 = ")"
    TokenBracket(bool isLeft);

    bool isLeftBracket() override;

    std::shared_ptr<Sign> getSign() override;
    double getNumber() override;
};


#endif /* end of include guard: TOKEN_BRACKET_H */
