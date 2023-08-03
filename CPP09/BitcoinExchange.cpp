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

void Bitcoin::fileToMap()
{
    std::ifstream ifs(this->_input);
    if (!ifs.is_open())
    {
        std::cout << "Error file" << std::endl;
        return ;
    }
    std::string line;
    std::string fLine;
    while (std::getline(ifs, line))
    {
        try
        {
            std::istringstream iss(readLine(line));
            iss
        }
        catch(const std::exception& e)
        {
            fLine = "Error: " + (std::string)e.what();
        }
        std::cout << fLine << std::endl;
    }
}
