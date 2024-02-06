#ifndef SIGNS_INFORMATION_H
#define SIGNS_INFORMATION_H

#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <string>

class SignsInformation
{
private:
    static std::unordered_map<std::string, int> signsPriorities;

public:
    SignsInformation() = delete;
    static int getSignPriority(std::string sign);

    static bool isSign(std::string str);

    static std::unordered_set<int> getValidPriorities();
};

#endif /* end of include guard: SIGNS_INFORMATION_H */
