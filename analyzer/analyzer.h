#ifndef ANALYZER_H
#define ANALYZER_H

#include <list>
#include <memory>
#include <unordered_map>
#include "../token/token_base.h"
#include "../sign/signs_information.h"

class Analyzer
{
private:
    std::unordered_map<int, int> priorities_;

public:
    Analyzer(std::list<std::shared_ptr<Token>>& tokens);
    Analyzer();

    int getHighPriority();

    void decrease(std::unordered_map<int, int> decreasedPriorities);
    std::unordered_map<int, int> getCurrentPriorities();

    void operator-=(Analyzer& decreasedAnalyzer);
};

#endif /* end of include guard: ANALYZER_H */
