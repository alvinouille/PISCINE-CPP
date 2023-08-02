#ifndef SPAN_H
# define SPAN_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
    private:
        Span();
        unsigned int _N;
        std::vector<unsigned int> stock;
    public:
        Span(unsigned int N);
        Span(Span const &copy);
        Span &operator=(Span const &rhs);
        ~Span();

        void addNumber(unsigned int nb);
        void addNumber(std::vector <unsigned int> supp);
        void printNumber()const;
        int shortestSpan();
        int longestSpan();

        class TooManyStockedException : public std::exception
        {
            public:
                char const *what() const throw();
        };
        class NotEnoughStockedException : public std::exception
        {
            public:
                char const *what() const throw();
        };
};

#endif