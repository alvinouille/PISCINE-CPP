#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>
#include <iostream>
#include <limits>
#include <sstream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const&copy);
        ScalarConverter &operator=(ScalarConverter const &rhs);
        ~ScalarConverter();

        void convert(std::string str);

        void convertLitt(std::string str)const;
        void convertChar(std::string str)const;
        void convertInt(std::string str)const;
        void convertFloat(std::string str)const;
        void convertDouble(std::string str)const;

        bool isLitt(std::string str)const;
        bool isChar(std::string str)const;
        bool isInt(std::string str)const;
        bool isFloat(std::string str)const;
        bool isDouble(std::string str)const;
    
    private:
        typedef void (ScalarConverter::*cT)(std::string)const;
        typedef bool (ScalarConverter::*tT)(std::string)const;
        cT convertType [5];
        tT typeType [5];
};

#endif