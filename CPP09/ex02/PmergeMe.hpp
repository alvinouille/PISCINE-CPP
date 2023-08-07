#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <sstream>
#include <sys/time.h>

template <typename T>
class PmergeMe
{
    public:
        PmergeMe() {}
        PmergeMe(PmergeMe const &copy) {(void) copy;}
        ~PmergeMe() {}
        PmergeMe &operator=(PmergeMe const &rhs)
        {
            if (this == &rhs)
                return (*this);
            return (*this);
        }

        void insertionSort(T &vec)
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

        T fusionSort(T &vec1, T &vec2)
        {
            size_t j = 0;
            size_t k = 0;
            size_t i = 0;
            size_t vsize = vec1.size() + vec2.size();
            T vec(vsize);
            
            for (i = 0 ; j != vec1.size() && k != vec2.size() ; i++)
                vec[i] = (vec1[j] < vec2[k]) ? vec1[j++] : vec2[k++];
            while (i < vsize)
                vec[i++] = (k == vec2.size() ? vec1[j++] : vec2[k++]);
            return (vec);
        }

        void divideToReign(T &vec)
        {
            size_t middle = vec.size() / 2;
            T vec1(vec.begin(), vec.begin() + middle);
            T vec2(vec.begin() + middle, vec.end());
            fordJohnsonSort(vec1);
            fordJohnsonSort(vec2);
            vec = fusionSort(vec1, vec2);
        }

        void fordJohnsonSort(T &vec)
        {
            if (vec.size() <= 32)
                insertionSort(vec);
            else
                divideToReign(vec);
        }

        void startChrono(std::clock_t begin)
        {
            this->_begin = begin;
        }

        void endChrono(std::clock_t end)
        {
            this->_end = end;
        }

        double resultChrono()const
        {
            return (static_cast<double>(this->_end - this->_begin) / static_cast<double>(CLOCKS_PER_SEC) * 1000.0);
        }

        private:
            std::clock_t _begin;
            std::clock_t _end;
};

#endif