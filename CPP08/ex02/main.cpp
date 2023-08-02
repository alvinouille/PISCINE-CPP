#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
    std::cout << std::endl << "<<< MUTANTSTACK ITERATIONS >>>" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl << "<<< LIST ITERATIONS >>>" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator itl = mlist.begin();
    std::list<int>::iterator itle = mlist.end();
    ++itl;
    --itl;
    while (itl != itle)
    {
        std::cout << *itl << std::endl;
        ++itl;
    }
    std::list<int> l(mlist);

    std::cout << std::endl << "<<< MUTANTSTACK REVERSED ITERATIONS >>>" << std::endl;
    MutantStack<int> mrstack;
    mrstack.push(5);
    mrstack.push(17);
    std::cout << mrstack.top() << std::endl;
    mrstack.pop();
    std::cout << mrstack.size() << std::endl;
    mrstack.push(3);
    mrstack.push(5);
    mrstack.push(737);
    mrstack.push(0);
    MutantStack<int>::reverse_iterator rit = mrstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mrstack.rend();
    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << std::endl << "<<< VECTOR REVERSED ITERATIONS >>>" << std::endl;
    std::vector<int> mvec;
    mvec.push_back(5);
    mvec.push_back(17);
    std::cout << mvec.back() << std::endl;
    mvec.pop_back();
    std::cout << mvec.size() << std::endl;
    mvec.push_back(3);
    mvec.push_back(5);
    mvec.push_back(737);
    //[...]
    mvec.push_back(0);
    std::vector<int>::reverse_iterator ritv = mvec.rbegin();
    std::vector<int>::reverse_iterator ritve = mvec.rend();
    ++ritv;
    --ritv;
    while (ritv != ritve)
    {
        std::cout << *ritv << std::endl;
        ++ritv;
    }
    return 0;
}