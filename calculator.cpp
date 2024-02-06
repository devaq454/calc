#include <algorithm>
#include <iostream>
#include <memory>
#include "calculator.h"
#include "converter/converter.h"

Calculator::Calculator(std::list<std::shared_ptr<Token>> tokens)
    : anlz{tokens}, tokens_{tokens} {}

Calculator::Calculator(std::string expression)
    : anlz{}
{
    tokens_ = Converter::convert(expression);
    anlz = Analyzer(tokens_);
}

double Calculator::calculateExpression()
{
    // идя от самого большого приоритета
    // пока остались 
    // вызвать рассчет -1 найденный +1
    // удалить от -1 найденный +1. добавить на место -1 новый токен с рассчитанным значением
    auto maxPrioritet = anlz.getHighPriority();
    do
    {
        auto itSign = std::find_if(tokens_.begin(), tokens_.end(), 
                [maxPrioritet](auto& i){
                if (i->isSign())
                {
                    return (i->getSign())->getPriority() == maxPrioritet;
                }
                    return false;
                }
            );

        if (itSign == tokens_.end())
        {
            throw std::runtime_error("no sign with prioritet: {" + std::to_string(maxPrioritet) + "}");
        }
        auto itLeftValue = std::next(itSign, -1);
        auto itRightValue = std::next(itSign, 1);
        auto leftValue = (*itLeftValue)->getNumber();
        auto rightValue = (*itRightValue)->getNumber();
        auto sign = (*itSign)->getSign();
        std::shared_ptr<Token> tokenResult = std::make_shared<TokenNumber>
            (calculateOperation(leftValue, rightValue, sign));
        tokens_.insert(itLeftValue, tokenResult);
        tokens_.erase(itLeftValue, ++itRightValue);
        maxPrioritet = anlz.getHighPriority();
    } while (maxPrioritet != -1);
    if (tokens_.size() != 1)
    {
        throw std::runtime_error("length of tokens_ must be = 1. but size is: {" + std::to_string(tokens_.size()) + "}");
    }
    else
    {
        return (*tokens_.begin())->getNumber();
    }
}

double Calculator::calculateOperation(double left, double right, std::shared_ptr<Sign> sign)
{
    return sign->getResult(left, right);
}
