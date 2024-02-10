#include <algorithm>
#include <iostream>
#include <memory>
#include "calculator.h"
#include "converter/converter.h"

Calculator::Calculator(std::list<std::shared_ptr<Token>> tokens)
    : anlz_{tokens}, tokens_{tokens} {}

Calculator::Calculator(std::list<std::shared_ptr<Token>> tokens,
        Analyzer&& anlz)
    : anlz_{anlz}, tokens_{tokens} {}

Calculator::Calculator(std::string expression)
    : anlz_{}
{
    tokens_ = Converter::convert(expression);
    anlz_ = Analyzer(tokens_);
}

double Calculator::calculateExpression()
{
    // если есть скобка то создать класс с выражением в этой скобке
    // чтобы найти конец нужно идти вправо от скобки создать счетчик скобок = 1
    // если встретилась левая, то +1 к счетчику, если правая то -1.
    // когда в счетчике будет ноль то значит это итератор конца элемента

    auto itLeftBracket = std::find_if(tokens_.begin(), tokens_.end(), 
            [](auto& i){
            return (i->isBracket());
            });

    // рекурсинвое решение сначало того, что в скобках, и замена подскобочного выражения на результат
    while (itLeftBracket != tokens_.end())
    {
        auto itRigthBracket = std::next(itLeftBracket, 1);
        
        // поиск итератора правой скобки
        auto count = 1;
        while (count != 0)
        {
            if ((*itRigthBracket)->isBracket())
            {
                count += (*itRigthBracket)->isLeftBracket() ? 1 : -1;
            }
            ++itRigthBracket;
        }
        std::list<std::shared_ptr<Token>> container(std::next(itLeftBracket, 1), std::next(itRigthBracket, -1));
        Analyzer innerAnlz(container);
        anlz_ -= innerAnlz;
        Calculator innerCalculator(std::move(container), std::move(innerAnlz));
        std::shared_ptr<Token> newToken = std::make_shared<TokenNumber>(innerCalculator.calculateExpression());
        tokens_.insert(itLeftBracket, newToken);
        tokens_.erase(itLeftBracket, itRigthBracket);
        itLeftBracket = std::find_if(tokens_.begin(), tokens_.end(), 
                    [](auto& i){
                    return (i->isBracket());
                    });
    }

    // базовый случай 
    

    auto itFunction = std::find_if(tokens_.begin(), tokens_.end(),
            [](auto& i){
                return i->isFunction();
            });
    while (itFunction != tokens_.end())
    {
        auto itValue = std::next(itFunction, 1);
        auto value = (*(std::next(itFunction, 1)))->getNumber();
        auto function = (*itFunction)->getFunction();
        std::shared_ptr<Token> newToken = std::make_shared<TokenNumber>(
                calculateFunction(value, function)
                );
        tokens_.insert(itFunction, newToken);
        tokens_.erase(itFunction, std::next(itFunction, 2));
        itFunction = std::find_if(tokens_.begin(), tokens_.end(),
            [](auto& i){
                return i->isFunction();
            });
    }

    // если остался только один токен - число.
    if (tokens_.size() == 1)
    {
        return (*tokens_.begin())->getNumber();
    }


    // рассчет знаков
    auto maxPrioritet = anlz_.getHighPriority();
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
        maxPrioritet = anlz_.getHighPriority();
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

double Calculator::calculateFunction(double value, std::shared_ptr<Function> funcction)
{
    return funcction->getResult(value);
}
