#include "PmergeMe.hpp"

int main()
{
    PmergeMe pm;
    std::vector<int> vec;
    std::srand(std::time(0));

    const int nbElem = 15;

    for (int i = 0; i < nbElem; ++i)
    {
        int nombre = std::rand();
        vec.push_back(nombre % 100);
    }

    std::cout << std::endl << "<<< BEFORE >>> :     ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t begin = clock();
    pm.fordJohnsonSort(vec);
    clock_t end = clock();

    std::cout << "<<< AFTER >>> :      ";
    for (size_t i = 0 ; i < vec.size() ; i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    double execTime = static_cast<double>((end - begin) * 1000.0 / CLOCKS_PER_SEC);
    std::cout << std::endl << "Time to process a range of " << nbElem;
    std::cout <<  " elements with std::vector : " << execTime << " ms" << std::endl;
}