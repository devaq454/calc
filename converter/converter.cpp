#include <regex>
#include "converter.h"
#include <memory>
#include "../sign/signs_information.h"
#include "../function/functions_information.h"
#include "../token/token_number.h"
#include "../token/token_sign.h"
#include "../token/token_bracket.h"
#include "../token/token_function.h"

std::list<std::shared_ptr<Token>> Converter::convert(std::string& expression)
{

    auto stream = std::stringstream(expression);
    std::list<std::shared_ptr<Token>> tokens{};
    std::string token;
    std::regex isDoubleRegex(R"(^([+-]?(?:[[:d:]]+\.?|[[:d:]]*\.[[:d:]]+))(?:[Ee][+-]?[[:d:]]+)?$)");
    auto isDouble = [isDoubleRegex](const auto& str)
    {
        return std::regex_match(str, isDoubleRegex); 
    };
    auto isSign = [](const auto& str)
    { 
        return SignsInformation::isSign(str); 
    };
    auto isBracket = [](const auto& str)
    { 
        return str == "(" || str == ")"; 
    };

    // TODO
    auto isFunction = [](const auto& str)
    {
        return FunctionsInformation::isFunction(str);
    };

    while (stream >> token)
    {
        // add token-number
        if(isDouble(token))
        {
            tokens.emplace_back(std::make_shared<TokenNumber>(token));
        }
        // add token-sign
        else if (isSign(token))
        {
            tokens.emplace_back(std::make_shared<TokenSign>(token));
        }
        // add token-bracket
        else if (isBracket(token))
        {
            tokens.emplace_back(std::make_shared<TokenBracket>(token));
        }
        else if (isFunction(token))
        {
            tokens.emplace_back(std::make_shared<TokenFunction>(token));
        }
        else
        {
            throw std::runtime_error("unkown token: {" + token + "}");
        }
    }

    return tokens;
}
