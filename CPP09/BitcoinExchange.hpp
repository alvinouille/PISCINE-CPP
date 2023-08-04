#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <stdexcept>

class Bitcoin
{
    public:
        class badInputE : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class notPositiveE : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class tooLargeE : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        Bitcoin(const char *input);
        Bitcoin(Bitcoin const &copy);
        ~Bitcoin();
        Bitcoin &operator=(Bitcoin const &rhs);

        void fileToMap();
        void printData(std::string date, float value);

    private:
        char const *_input;
        std::map<std::string, float> dbMap;

        Bitcoin();

        std::string formatLine(std::string str)const;
        std::string formatDate(std::string str)const;
        float formatValue(std::string str)const;
        void dbToMap();
};

#endif