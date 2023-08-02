#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.printNumber();
        std::cout << "Shortest : " << sp.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try 
    {
        Span sp2(20000);
        std::vector<unsigned int> v;
        for (int i = 0 ; i < 20000 ; i++)
            v.push_back(i * 3);
        sp2.addNumber(v);
        // sp2.printNumber();
        std::cout << "Shortest : " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest : " << sp2.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

}