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


bool isChar(std::string str)
{
    if (str.size() == 1)
    {
        if (str[0] >= '0' && str[0] <= '9')
            return (false);
        return (true);
    }
    return (false);
}

bool isInt(std::string str)
{
    int i = 0;
    int value;
    long value2;
    std::istringstream iss(str);
    std::istringstream iss2(str);

    if (str[0] == '-')
        i++;
    while (str[i])
    {
        if (str[i] == '.' || (str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z'))
            return (false);
        i++; 
    }
    if ((iss >> value).fail())
        return (false);
    iss2 >> value2;
    if (value2 < -2147483648 || value2 > 2147483647)
        return (false);
    return (true);
}

bool isFloat(std::string str)
{
    std::size_t i = 0;
    int point = 0;
    float value;
    std::istringstream iss(str);

    if (str[0] == '-')
        i++;
    while (str[i] && i < str.size())
    {
        if (str[i] == '.')
        {
            if (!point)
                point++;
            else
                return (false);
        }
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i] == 'f')
            {
                if (str[i + 1] != '\0')
                    return (false);
                break;
            }
            return (false);
        }
        i++; 
    }
    if (str[str.size() - 1] != 'f' || !point)
        return (false);
    if ((iss >> value).fail())
        return (false);
    if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
        return (false);
    return (true);
}

bool isDouble(std::string str)
{
    std::size_t i = 0;
    int point = 0;
    double value;
    std::istringstream iss(str);

    if (str[0] == '-')
        i++;
    while (str[i] && i < str.size())
    {
        if (str[i] == '.')
        {
            if (!point)
                point++;
            else
                return (false);
        }
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            return (false);
        i++; 
    }
    if (str[i - 1] == '.' || !point)
        return (false);
    if ((iss >> value).fail())
        return (false);
    if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())
        return (false);
    return (true);
}

bool isLitt(std::string str)
{
    if (str == "-inf" || str == "+inf" || str == "nan" 
        || str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    return (false);
}

void ScalarConverter::convert(std::string str)
{
    if (isLitt(str))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << (str == "nanf" || str == "-inff" || str == "+inff" ? "" : "f") << std::endl;
		std::cout << "double: " << (str == "nanf" ? "nan" : str) << std::endl;
    }
    else if (isChar(str))
    {
        std::cout << "char: '" << str[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    }
    else if (isInt(str))
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
    else if (isFloat(str))
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
    else if (isDouble(str))
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
        if (value >= static_cast<double>(std::numeric_limits<float>::min()) && value < static_cast<double>(std::numeric_limits<float>::max()))
            std::cout << "float: " << static_cast<float>(value) << (static_cast<float>(value) == static_cast<int>(value) ? ".0f" : "f") << std::endl;
        else
            std::cout << "float: impossible" << std::endl;
        std::cout << "double: " << value << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}