#include "validator.h"
#include <list>
#include <regex>
#include <memory>
#include "../sign/signs_information.h"
#include "../function/functions_information.h"
#include "../token/token_number.h"
#include "../token/token_sign.h"
#include "../token/token_bracket.h"
#include "../token/token_function.h"


bool Validator::checkSymbols(std::string& expression)
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
            throw std::runtime_error("unknown symbol: { " + token +" }");
            return false;
        }
    }

    // first token can't be a sign
    if (tokens.size() == 0)
        return true;
    auto first = *(tokens.begin());
    if (tokens.size() == 1)
    {
        if (first->isNumber())
            return true;
        throw std::runtime_error("sign or function can't be solo");
    }
    if (first->isSign())
        throw std::runtime_error("sign { " + first->getValue() + " } without number left");
    // TODO it's too boring!!
    for (auto currentIt = std::next(tokens.begin(), 1);
             currentIt != std::next(tokens.end(), -1); ++currentIt)
    {
        auto last = *(std::next(currentIt, -1));
        auto current = *currentIt;
        if (current->isNumber())
        {
            if (last->isNumber())
            {
                throw std::runtime_error("can't be number after number");
            }
        }
        if (current->isFunction())
        {
            if (last->isFunction())
            {
                throw std::runtime_error("can't be function after function");
            }
        }
        if (current->isSign())
        {
            if (last->isSign())
            {
                throw std::runtime_error("can't be sign after sign");
            }
        }
        if (current->isBracket())
        {
            if (last->isBracket())
            {
                if (last->isLeftBracket() && (!current->isLeftBracket()))
                {
                    throw std::runtime_error("can't be 2 brackets like this: ()");
                }
            }
        }
    }
    return true;
}

bool Validator::checkBrackets(std::string& string)
{
    auto leftOpen = 0;
    auto rightOpen = 0;
    auto i = string[0];
    for (auto i : string)
    {
        if (std::string(1, i) == "(")
            ++leftOpen;
        if (std::string(1, i) == ")")
        {
            ++rightOpen;
            if (rightOpen > leftOpen)
            {
                throw std::runtime_error("invalid brackets");
                return false;
            }
        }
    }
    if (leftOpen != rightOpen)
            throw std::runtime_error("invalid brackets");
    return true;
}

bool Validator::checkExpression(std::string& expression)
{
    return checkBrackets(expression) && checkSymbols(expression);
    /* return checkBrackets(expression) && checkSymbols(expression); */
}
