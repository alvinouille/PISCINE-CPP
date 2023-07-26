#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    if (this == &rhs)
        return (*this);
    return (*this);
}

void ScalarConverter::convert(std::string str)
{
    
}