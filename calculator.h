#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <list>
#include <memory>
#include "token/token_base.h"
#include "token/token_number.h"
#include "analyzer/analyzer.h"

class Calculator
{
private:
    std::list<std::shared_ptr<Token>> tokens_;
    Analyzer anlz_;

public:
    Calculator(std::string expression);
    Calculator(std::list<std::shared_ptr<Token>> tokens);
    Calculator(std::list<std::shared_ptr<Token>> tokens, Analyzer&& anlz);

    double calculateExpression();

    double calculateOperation(double left, double right, std::shared_ptr<Sign> sign);

    double calculateFunction(double value, std::shared_ptr<Function> function);
};


#endif /* end of include guard: CALCULATOR_H_ */
