#include "signs_information.h"
#include <stdexcept>



std::unordered_map<std::string, int> SignsInformation::signsPriorities = 
{
    {"+", 100},
    {"-", 100},
    {"*", 101},
    {"/", 101},
};

int SignsInformation::getSignPriority(std::string sign)
{
    if (SignsInformation::signsPriorities.find(sign) == signsPriorities.end())
    {
        throw std::runtime_error("no priority for : {" + sign + "}");
    }
    return SignsInformation::signsPriorities.at(sign);
}

bool SignsInformation::isSign(std::string str)
{
    return signsPriorities.count(str);
}

std::unordered_set<int> SignsInformation::getValidPriorities()
{
    std::unordered_set<int> validPriorities;
    for (const auto& i : signsPriorities)
    {
        validPriorities.insert(i.second);
    }
    return validPriorities;
}

