#ifndef TOKEN_FUNCTION_H
#define TOKEN_FUNCTION_H
#include "token_base.h"

class TokenFunction : public Token
{
private:
    std::shared_ptr<Function> function_;

public:
    TokenFunction(std::string function);

    std::shared_ptr<Function> getFunction() override;

    std::shared_ptr<Sign> getSign() override;
    double getNumber() override;
    bool isLeftBracket() override;
};


#endif /* end of include guard: TOKEN_FUNCTION_H */
