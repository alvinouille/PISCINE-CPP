#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(Span const &copy) : _N(copy._N)
{
    *this = copy;
}

Span &Span::operator=(Span const &rhs)
{
    if (this == &rhs)
        return (*this);
    this->_N = rhs._N;
    std::copy(rhs.stock.begin(), rhs.stock.end(), this->stock.begin());
    return (*this);
}

void Span::addNumber(unsigned int nb)
{
    if (stock.size() < this->_N)
        stock.push_back(nb);
    else
        throw Span::TooManyStockedException();
}

void Span::addNumber(std::vector <unsigned int> supp)
{
    if (supp.size() + this->stock.size() <= this->_N)
        this->stock.insert(this->stock.end(), supp.begin(), supp.end());
    else
        throw Span::TooManyStockedException();
}

int Span::shortestSpan()
{
    unsigned int minVal;
    int i = 1;
    std::vector<unsigned int>::iterator it;
    if (stock.size() > 1)
    {
        std::sort(this->stock.begin(), this->stock.end());
        minVal = this->stock[1] - this->stock[0];
        for (it = this->stock.begin() ; it != this->stock.end() ; ++it, ++i)
        {
            if (this->stock[i] - this->stock[i - 1] < minVal)
                minVal = this->stock[i] - this->stock[i - 1];
        }
        return (minVal);
    }
    else
        throw Span::NotEnoughStockedException();
}

int Span::longestSpan()
{
    if (stock.size() > 1)
    {
        std::sort(stock.begin(), stock.end());
        return (stock[stock.size() - 1] - stock[0]);
    }
    else
        throw Span::NotEnoughStockedException();
}

void Span::printNumber()const
{
    std::vector<unsigned int>::const_iterator it;
    for (it = this->stock.begin() ; it != this->stock.end() ; ++it)
    {
        std::cout << *it << std::endl;
    }
}

char const *Span::TooManyStockedException::what()const throw()
{
    return ("Too many number stocked (Exception)");
}

char const *Span::NotEnoughStockedException::what()const throw()
{
    return ("Not enough number stocked to calcul (Exception)");
}