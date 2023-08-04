#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(const char *input) : _input(input) {}

Bitcoin::~Bitcoin() {}

Bitcoin::Bitcoin(Bitcoin const &copy) : _input(copy._input) {}

Bitcoin &Bitcoin::operator=(Bitcoin const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_input = rhs._input;
    return (*this);
}

const char *Bitcoin::badInputE::what() const throw()
{
    return ("bad input => ");
}

const char *Bitcoin::notPositiveE::what() const throw ()
{
    return ("not a positive number.");
}

const char *Bitcoin::tooLargeE::what() const throw ()
{
    return ("too large number.");
}


std::string Bitcoin::formatLine(std::string str)const
{
    std::istringstream iss(str);
    std::string word, last(""), fLine("");

    for (int i = 0 ; i < 4 ; i++)
    {
        iss >> word;
        if ((i < 3 && word == last) || (i == 3 && word != last))
        {
            throw Bitcoin::badInputE();
            break;
        }
        last = word;
        if (i == 1)
        {
            size_t found = word.find("|");
            if (word.size() != 1 || found)
            {
                throw Bitcoin::badInputE();
                break;
            }
        }
        if (i == 0 || i == 2)
            fLine += (word + " ");
    }
    return (fLine);
}

static bool dayCheck(int day, int month)
{
    if (day < 1)
        return (0);
    if (month == 2 && day > 28)
        return (0);
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return (0);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (0);
    return (1);
}

std::string Bitcoin::formatDate(std::string str)const
{
    int year, month, day;
    char delimiter;
    std::ostringstream oss;
    std::istringstream iss(str);

    iss >> year >> delimiter;
    if (year > 2022 || year < 2009 || delimiter != '-')
        throw Bitcoin::badInputE();
    iss >> day >> delimiter >> month;
    if (month > 12 || month < 1 || !dayCheck(day, month) || delimiter != '-')
        throw Bitcoin::badInputE();
    
    oss << year << "-" << day << "-" << month;
    return (oss.str());
}

float Bitcoin::formatValue(std::string str)const
{
    std::istringstream iss(str);
    std::string trash;
    float value;
    
    iss >> trash >> value;
    if (value < 0)
        throw Bitcoin::notPositiveE();
    else if (value > 1000)
        throw Bitcoin::tooLargeE();
    else
        return (value);
}

void Bitcoin::fileToMap()
{
    std::ifstream ifs(this->_input);
    if (!ifs.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }
    std::string line, fLine, date;
    float value;

    while (std::getline(ifs, line))
    {
        try
        {
            fLine = formatLine(line);
            date = formatDate(fLine);
            value = formatValue(fLine);
            // std::cout << date << " => " << value << std::endl;
            this->_map[date] = value;
            // std::cout << std::endl << "ici" << std::endl;
        }
        catch(const Bitcoin::badInputE &e)
        {
            this->_map[std::string(e.what()) + fLine] = -1;

        }
        catch(const std::exception &e)
        {
            this->_map[e.what()] = -2;
        }
    }
}

std::map<std::string, float> Bitcoin::dbToMap()
{
    std::ifstream ifs("data.csv");
    std::map<std::string, float> dbMap;
    std::string line, date;
    char delimiter;
    float value;

    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        iss >> date >> delimiter >> value;
        dbMap[date] = value;
    }
    return (dbMap);
}

void Bitcoin::printData()
{
    std::map<std::string, float> dbMap = dbToMap();
    std::map<std::string, float>::iterator _it;
    std::map<std::string, float>::iterator dit;
    for (_it = this->_map.begin() ; _it != this->_map.end() ; _it++)
    {
        std::cout << _it->first << " => " << _it->second << std::endl;
        if (_it->second != -1 && _it->second != -2)
        {
            // std::cout << " <<< " << _it->first << " | " << _it->second << std::endl;
            for (dit = dbMap.begin() ; dit != dbMap.end() ; ++dit)
            {
                if (_it->first == dit->first)
                {
                    std::cout << _it->first << " => " << _it->second << " = " << static_cast<float>(dit->second * _it->second);
                    break;
                }
            }
            std::cout << _it->first << " not found exact date";
        }
        else
            std::cout << "Error: " << _it->first;
        std::cout << std::endl;
    }
}