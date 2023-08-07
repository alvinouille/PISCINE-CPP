#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    // <<<<<< VECTORS SORT >>>>>>>
    PmergeMe<std::vector<unsigned int> > pmV(ac, av);

    pmV.printCont(BEFORE);

    pmV.startChrono(std::clock());
    pmV.fordJohnsonSort();
    pmV.endChrono(std::clock());

    pmV.printCont(AFTER);

    pmV.printChrono("std::vector<unsigned int>");


    // <<<<<<< DEQUES SORT >>>>>>>
    PmergeMe<std::deque<unsigned int> > pmD(ac, av);

    pmD.startChrono(std::clock());
    pmD.fordJohnsonSort();
    pmD.endChrono(std::clock());

    pmD.printChrono("std::deque<unsigned int>");
}