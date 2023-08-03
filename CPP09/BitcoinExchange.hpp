#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class Bitcoin
{
    public:
        Bitcoin(const char *input);
        Bitcoin(Bitcoin const &copy);
        ~Bitcoin();
        Bitcoin &operator=(Bitcoin const &rhs);
        void fileToMap();
        void printMap();

    private:
        char const *_input;
        std::map<std::string, float> _map;

        Bitcoin();

        bool formatLine()const;
        bool formatDate()const;
        bool formatValue()const;
        std::string readLine(std::string str)const;
};

#endif