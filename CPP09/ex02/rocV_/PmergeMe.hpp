#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>


class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &copy);
        ~PmergeMe();
        PmergeMe &operator=(PmergeMe const &rhs);

        void insertionSort(std::vector<int> &vec);
        std::vector<int> fusionSort(std::vector<int> &vec1, std::vector<int> &vec2);
        void fordJohnsonSort(std::vector<int> &vec);   
        void divideToReign(std::vector<int> &vec);
};

#endif