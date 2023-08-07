#include "PmergeMe.hpp"

static int digitValue(std::string value)
{
    unsigned int nb;
    std::istringstream iss(value);
    for (size_t i = 0 ; i < value.size() ; i++)
    {
        if (!std::isdigit(value[i]))
            return (-1);
    }
    iss >> nb;
    return (nb);
}

int main(int ac, char **av)
{
    PmergeMe <std::vector<int> > pmV;
    PmergeMe <std::deque<int> > pmD;
    std::vector<int> vec;
    std::deque<int> dq;

    for (int i = 1 ; i < ac ; i++)
    {
        int value = digitValue(std::string(av[i]));
        if (value == -1)
            return (std::cout << "Error: Wrong input" << std::endl), 1;
        vec.push_back(value);
        dq.push_back(value);
    }

    std::cout << std::endl << "<<< BEFORE >>> :     ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    pmV.startChrono(std::clock());
    pmV.fordJohnsonSort(vec);
    pmV.endChrono(std::clock());

    pmD.startChrono(std::clock());
    pmD.fordJohnsonSort(dq);
    pmD.endChrono(std::clock());

    std::cout << "<<< AFTER >>> :      ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl << "Time to process a range of " << vec.size();
    std::cout <<  " elements with std::vector : " ;
    std::cout.precision(6);
    std::cout << pmV.resultChrono() << " ms" << std::endl;

    std::cout << "Time to process a range of " << dq.size();
    std::cout <<  " elements with std::deque : ";
    std::cout.precision(6);
    std::cout << pmD.resultChrono() << " ms" << std::endl;
}