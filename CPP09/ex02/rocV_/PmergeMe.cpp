#include "PmergeMe.hpp"

// PmergeMe::PmergeMe(std::vector<int> vec) : _vec(0), _sorted(false) {}

// PmergeMe::PmergeMe(std::vector<int>::iterator b, std::vector<int>::iterator e)
// {
//     _vec(b, e);
//     this->_sorted = 0;
// }

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &copy) { (void) copy;}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this == &rhs)
        return (*this);
    return (*this);
}

void PmergeMe::insertionSort(std::vector<int> &vec)
{
    int tmp;

    for (size_t i = 1 ; i < vec.size() ; i++)
    {
        if (vec[i - 1] > vec[i])
        {
            tmp = vec[i];
            while (i > 0 && vec[i - 1] > tmp)
            {
                vec[i] = vec[i - 1];
                i--;
            }
            vec[i] = tmp;
        }
    }
}

std::vector<int> PmergeMe::fusionSort(std::vector<int> &vec1, std::vector<int> &vec2)
{
    size_t j = 0;
    size_t k = 0;
    size_t i = 0;
    size_t vsize = vec1.size() + vec2.size();
    std::vector<int> vec(vsize);
    
    for (i = 0 ; j != vec1.size() && k != vec2.size() ; i++)
        vec[i] = (vec1[j] < vec2[k]) ? vec1[j++] : vec2[k++];
    while (i < vsize)
        vec[i++] = (k == vec2.size() ? vec1[j++] : vec2[k++]);
    return (vec);
}

void PmergeMe::divideToReign(std::vector<int> &vec)
{
    size_t middle = vec.size() / 2;
    
    std::vector<int> vec1(vec.begin(), vec.begin() + middle);
    std::vector<int> vec2(vec.begin() + middle, vec.end());
    fordJohnsonSort(vec1);
    fordJohnsonSort(vec2);
    vec = fusionSort(vec1, vec2);
}
void PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
    if (vec.size() <= 32)
        insertionSort(vec);
    else
        divideToReign(vec);
}

