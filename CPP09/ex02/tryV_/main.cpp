#include "PmergeMe.hpp"

int main()
{
    PmergeMe <std::vector<int> > pmV;
    PmergeMe <std::deque<int> > pmD;
    std::vector<int> vec;
    std::deque<int> dq;
    std::srand(std::time(0));

    const int nbElem = 15;

    for (int i = 0; i < nbElem; ++i)
    {
        int nombre = std::rand();
        vec.push_back(nombre % 100);
        dq.push_back(nombre % 100);
    }

    std::cout << std::endl << "<<< BEFORE >>> :     ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t beginV = clock();
    pmV.fordJohnsonSort(vec);
    clock_t endV = clock();

    clock_t beginD = clock();
    pmD.fordJohnsonSort(dq);
    clock_t endD = clock();

    std::cout << "<<< AFTER >>> :      ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    double timeV = static_cast<double>((endV - beginV) * 1000.0 / CLOCKS_PER_SEC);
    std::cout << std::endl << "Time to process a range of " << nbElem;
    std::cout <<  " elements with std::vector : " << timeV << " ms" << std::endl;

    double timeD = static_cast<double>((endD - beginD) * 1000.0 / CLOCKS_PER_SEC);
    std::cout << "Time to process a range of " << nbElem;
    std::cout <<  " elements with std::deque : " << timeD << " ms" << std::endl;
}