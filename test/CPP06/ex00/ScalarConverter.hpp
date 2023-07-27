#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <limits>
#include <sstream>

# define F 0
# define D 1

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const&copy);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter();

        void convert(std::string str);
};

#endif