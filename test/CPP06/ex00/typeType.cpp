#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string str)const
{
    if (str.size() == 1)
    {
        if (str[0] >= '0' && str[0] <= '9')
            return (false);
        return (true);
    }
    return (false);
}

bool ScalarConverter::isInt(std::string str)const
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

bool ScalarConverter::isFloat(std::string str)const
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
    if (str[str.size() - 1] != 'f' || !point || (point && str[str.size() - 2] == '.'))
        return (false);
    iss >> value;
  	if (iss.fail() || value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) 
    	return false;
    return (true);
}

bool ScalarConverter::isDouble(std::string str)const
{
    std::size_t i = 0;
    int point = 0;
    std::istringstream iss(str);
    double value;

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
    iss >> value;
    if (iss.fail() || value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
        return false;
    return (true);
}

bool ScalarConverter::isLitt(std::string str)const
{
    if (str == "-inf" || str == "+inf" || str == "nan" 
        || str == "-inff" || str == "+inff" || str == "nanf")
        return (true);
    return (false);
}