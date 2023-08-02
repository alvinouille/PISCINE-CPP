#include "ScalarConverter.hpp"

void ScalarConverter::convertLitt(std::string str)const
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << (str == "nanf" || str == "-inff" || str == "+inff" ? "" : "f") << std::endl;
    std::cout << "double: " << (str == "nanf" ? "nan" : (str == "-inff" ? "-inf" : (str == "+inff" ? "+inf" : str))) << std::endl;
}

void ScalarConverter::convertChar(std::string str)const
{
    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void ScalarConverter::convertInt(std::string str)const
{
    int value;
    std::istringstream iss(str);
    iss >> value;
    if (value >= ' ' && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if ((value >= 0 && value < 32) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(std::string str)const
{
    float value;
    std::istringstream iss(str);
    iss >> value;
    if (value >= ' ' && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if ((value >= 0 && value < 32) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (value >= static_cast<float>(-2147483648) && value < static_cast<float>(2147483647))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << (value == static_cast<int>(value) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << static_cast<double>(value) << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}

void ScalarConverter::convertDouble(std::string str)const
{
    double value;
    std::istringstream iss(str);
    iss >> value;
    if (value >= ' ' && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if ((value >= 0 && value < 32) || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    if (value >= static_cast<double>(-2147483648) && value < static_cast<double>(2147483647))
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (value >= static_cast<double>(std::numeric_limits<float>::min()) || value < static_cast<double>(std::numeric_limits<float>::max()))
        std::cout << "float: " << static_cast<float>(value) << (static_cast<float>(value) == static_cast<int>(value) ? ".0f" : "f") << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    std::cout << "double: " << value << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}