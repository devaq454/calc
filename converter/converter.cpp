#include <regex>
#include "converter.h"
#include <memory>
#include "../sign/signs_information.h"
#include "../token/token_number.h"
#include "../token/token_sign.h"

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

    while (stream >> token)
    {
        // знак 
        if(isDouble(token))
        {
            tokens.emplace_back(std::make_shared<TokenNumber>(token));
        }
        else if (isSign(token))
        {
            // add token sign
            tokens.emplace_back(std::make_shared<TokenSign>(token));
        }
        else if (isBracket(token))
        {
            // add token bracket
        }
        else
        {
            throw std::runtime_error("unkown token: {" + token + "}");
        }
    }

    return tokens;
}
