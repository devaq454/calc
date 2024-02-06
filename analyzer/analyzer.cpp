#include "analyzer.h"

Analyzer::Analyzer(std::list<std::shared_ptr<Token>>& tokens)
{
    for (const auto& priority : SignsInformation::getValidPriorities())
    {
        priorities_[priority] = 0;
    }
    for (const auto& token : tokens)
    {
        if (token->isSign())
        {
            priorities_[token->getSign()->getPriority()] += 1;
        }
    }
}

Analyzer::Analyzer()
    : priorities_{}
{
    for (const auto& priority : SignsInformation::getValidPriorities())
    {
        priorities_[priority] = 0;
    }
}


int Analyzer::getHighPriority()
{
    int max = -1;
    for (const auto& priority : priorities_)
    {
        if (priority.second != 0)
            max = std::max(max, priority.first);
    }
    if (max != -1)
    {
        --priorities_.at(max);
    }
    // return -1 if no signs left
    return max;
}

std::unordered_map<int, int> Analyzer::getCurrentPriorities()
{
    std::unordered_map<int, int> currentPriorities;
    
    for (const auto& priority : priorities_)
    {
        if (priority.second != 0)
        {
            currentPriorities.insert(priority);
        }
    }

    return currentPriorities;
}

void Analyzer::decrease(std::unordered_map<int, int> decreasedPriorities)
{
    for (const auto& priority : decreasedPriorities)
    {
        priorities_[priority.first] -= priority.second;
    }
}

void Analyzer::operator-=(Analyzer& decreasedAnalyzer)
{
    this->decrease(decreasedAnalyzer.getCurrentPriorities());
}
