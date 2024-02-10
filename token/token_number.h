#ifndef TOKEN_NUMBER_H
#define TOKEN_NUMBER_H

#include "token_base.h"

class TokenNumber : public Token
{
private:
    double number_;

public:
    TokenNumber(std::string number);
    TokenNumber(double number);

    double getNumber() override;

    void setNumber(double number);

    std::shared_ptr<Sign> getSign() override;
    bool isLeftBracket() override;
    std::shared_ptr<Function> getFunction() override;
};


#endif /* end of include guard: TOKEN_NUMBER_H */
