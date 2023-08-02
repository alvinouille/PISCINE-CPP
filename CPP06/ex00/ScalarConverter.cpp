#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
    convertType[0] = &ScalarConverter::convertLitt;
    convertType[1] = &ScalarConverter::convertChar;
    convertType[2] = &ScalarConverter::convertInt;
    convertType[3] = &ScalarConverter::convertFloat;
    convertType[4] = &ScalarConverter::convertDouble;
    typeType[0] = &ScalarConverter::isLitt;
    typeType[1] = &ScalarConverter::isChar;
    typeType[2] = &ScalarConverter::isInt;
    typeType[3] = &ScalarConverter::isFloat;
    typeType[4] = &ScalarConverter::isDouble;
}

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
    for (int i = 0 ; i < 5 ; i++)
    {
        if ((this->*typeType[i])(str))
        {
            (this->*convertType[i])(str);
            return;
        }
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}