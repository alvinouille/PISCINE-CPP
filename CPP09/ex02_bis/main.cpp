#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmV(ac, av);

    std::vector<int> start = pmV.getter();
    
    for (size_t i = 0 ; i < start.size() ; i++)
        std::cout << start[i] << " ";
    std::cout << std::endl;
    
    std::vector<int> res = pmV.launcher();

    // for (size_t i = 0 ; i < res.size() ; i++)
    //     std::cout << res[i] << " ";
    // std::cout << std::endl;
}