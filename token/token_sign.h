#ifndef TOKEN_SIGN_H
#define TOKEN_SIGN_H

#include <memory>
#include "token_base.h"
#include "../sign/sign_base.h"

class TokenSign : public Token
{
private:
    std::shared_ptr<Sign> sign_;

public:
    TokenSign(std::string sign);

    std::shared_ptr<Sign> getSign() override;


    double getNumber() override;
    bool isLeftBracket() override;
};


#endif /* end of include guard: TOKEN_SIGN_H */
