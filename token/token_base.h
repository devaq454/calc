#ifndef BASE_TOKEN_H 
#define BASE_TOKEN_H

#include <memory>
#include <string>
#include <unordered_map>
#include "../sign/sign_base.h"

class Token
{
private:
    std::string value_;
    bool isSign_, isNumber_, isBracket_;


public:
    Token(std::string value);

    std::string getValue();

    void setValue(std::string value);

    bool isSign();
    bool isNumber();
    bool isBracket();

    void setIsSign(bool isSign);
    void setIsNumber(bool isNumber);
    void setIsBracket(bool isBracket);

    // for token-number
    virtual double getNumber() = 0;

    // for token-sign
    virtual std::shared_ptr<Sign> getSign() = 0;

    // for token-bracket
    virtual bool isLeftBracket() = 0;
};


#endif /* end of include guard: BASE_TOKEN_H */
