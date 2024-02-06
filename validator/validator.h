#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <memory>
#include <string>

class Validator
{
private:
    bool checkSymbols(std::string& expression);
    bool checkBrackets(std::string& expression);

public:
    Validator() = delete;

    static bool checkExpression(std::string& expression);
};


#endif /* end of include guard: VALIDATOR_H */
