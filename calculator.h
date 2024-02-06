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
    Analyzer anlz;

public:
    Calculator(std::string expression);
    Calculator(std::list<std::shared_ptr<Token>> tokens);

    double calculateExpression();

    double calculateOperation(double left, double right, std::shared_ptr<Sign> sign);
};


#endif /* end of include guard: CALCULATOR_H_ */
