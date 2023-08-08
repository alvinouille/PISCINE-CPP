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

static bool digitValue(std::string value)
{
    int point = 0;

    if (value[0] == '.' || value[value.size() - 1] == '.')
        return (false);
    for (size_t i = 0 ; i < value.size() ; i++)
    {
        if (!std::isdigit(value[i]) && (value[i] == '.' && point))
            return (false);
        if (value[i] == '.')
            point = 1;
    }
    return (true);
}

std::string Bitcoin::formatLine(std::string str)const
{
    std::istringstream iss(str);
    std::string word, last(""), fLine("");

    for (int i = 0 ; i < 4 ; i++)
    {
        iss >> word;
        if ((i < 3 && word == last) || (i == 3 && !iss.fail()))
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
        if ((i == 0 && word.size() == 10) || (i == 2 && digitValue(word)))
            fLine += (word + " ");
        else if (i == 0 || i == 2)
        {
            throw Bitcoin::badInputE();
            break;
        }
    }
    return (fLine);
}

static bool dayCheck(int day, int month, int year)
{
    if (day < 1)
        return (false);
    if (year == 2009 && month == 1 && day < 2)
        return (false);
    if (month == 2)
    {
        if (year != 2012 && year != 2016 && year != 2020 && day > 28)
            return (false);
        else if (day > 29)
            return (false);
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    return (true);
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
    iss >> month >> delimiter >> day;
    if (month > 12 || month < 1 || !dayCheck(day, month, year) || delimiter != '-')
        throw Bitcoin::badInputE();
    
    oss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
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
    if (!dbToMap())
        return ;
    std::ifstream ifs(this->_input);
    std::string line, fLine, date;
    float value;
    if (!ifs.is_open())
        return void(std::cout << "Error: could not open file." << std::endl);

    std::getline(ifs, line);
    while (std::getline(ifs, line))
    {
        try
        {
            fLine = formatLine(line);
            date = formatDate(fLine);
            value = formatValue(fLine);
            printData(date, value);
        }
        catch(const Bitcoin::badInputE &e)
        {
            std::cout << "Error: " << e.what() << line << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    ifs.close();
}

int Bitcoin::dbToMap()
{
    std::ifstream ifs("data.csv");
    std::string line, date;
    float value;
    if (!ifs.is_open())
        return ((std::cout << "Error: could not open file." << std::endl), 0);

    while (std::getline(ifs, line))
    {
        line.replace(line.find(","), 1, " ");
        std::istringstream iss(line);
        iss >> date >> value;
        this->dbMap[date] = value;
    }
    ifs.close();
    return (1);
}

void Bitcoin::printData(std::string date, float value)
{
    (void)value;
    (void)date;
    std::map<std::string, float>::iterator it = this->dbMap.lower_bound(date);
    
    if (it->first != date && it != this->dbMap.begin())
        --it;
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
