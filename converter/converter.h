#ifndef CONVERTER_H
#define CONVERTER_H

#include <sstream>
#include <string>
#include <list>
#include "../token/token_base.h"

class Converter
{
public:
    Converter() = delete;

    static std::list<std::shared_ptr<Token>> convert(std::string& expression);
};


#endif /* end of include guard: CONVERTER_H */
