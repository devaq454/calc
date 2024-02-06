#ifndef SIGNS_POINTERS_H
#define SIGNS_POINTERS_H

#include <memory>
#include <string>
#include <unordered_map>
#include "sign_base.h"

class SignsPointers
{
private:
    static std::unordered_map<std::string, std::shared_ptr<Sign>> signSharedPtrs;

public:
    SignsPointers() = delete;

    static std::shared_ptr<Sign> getSignSharedPtr(std::string sign);
};

#endif /* end of include guard: SIGNS_POINTERS_H */
