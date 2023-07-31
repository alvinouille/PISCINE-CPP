#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
    int res;
    
    std::cout << "<<< Vectors >>>" << std::endl;
    std::vector<int> v;
    int occ = 1523;
    v.push_back(1);
    v.push_back(42);
    v.push_back(1523);
    std::vector<int>::iterator it;
    for (it = v.begin() ; it != v.end() ; ++it)
    {
        std::cout << "[" << std::distance(v.begin(), it) << "] : " << *it << std::endl;
    }
    try
    {
        res = easyfind(v, occ);
        std::cout << "Occurence " << occ << " found at the index " <<  res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Occurence " << occ << " not found" << std::endl;
    }

    std::cout << "<<< lists >>>" << std::endl;
    std::list<int> l;
    occ = 42;
    int i = 0;
    l.push_back(1);
    l.push_back(42);
    l.push_back(1523);
    std::list<int>::const_iterator itl;
    for (itl = l.begin() ; itl != l.end() ; ++itl, ++i)
    {
        std::cout << "[" << i << "] : " << *itl << std::endl;
    }
    try
    {
        res = easyfind(l, occ);
        std::cout << "Occurence " << occ << " found at the index " <<  res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Occurence " << occ << " not found" << std::endl;
    }

    std::cout << "<<< Deque >>>" << std::endl;
    std::deque<int> d;
    i = 0;
    occ = -1;
    d.push_back(1);
    d.push_back(42);
    d.push_back(1523);
    std::deque<int>::const_iterator itd;
    for (itd = d.begin() ; itd != d.end() ; ++itd, ++i)
    {
        std::cout << "[" << i << "] : " << *itd << std::endl;
    }
    try
    {
        res = easyfind(d, occ);
        std::cout << "Occurence " << occ << " found at the index " <<  res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Occurence " << occ << " not found" << std::endl;
    }
}