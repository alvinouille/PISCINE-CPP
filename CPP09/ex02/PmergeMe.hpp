#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <sstream>
#include <stdexcept>

# define BEFORE 0
# define AFTER 1

template <typename T>
class PmergeMe
{
    public:
        PmergeMe(int size, char **nb)
        {
            for (int i = 1 ; i < size ; i++)
            {
                if (std::string(nb[i]) == "")
                    throw (std::exception());
                int value = PmergeMe::digitValue(std::string(nb[i]));
                if (value == -1)
                    throw (std::exception());
                this->_cont.push_back(value);
            }
        }
        PmergeMe(T const &cont) : _cont(cont) {}
        PmergeMe(PmergeMe const &copy) : _cont(copy._cont), _begin(copy._begin), _end(copy._end) {(void) copy;}
        ~PmergeMe() {}
        PmergeMe &operator=(PmergeMe const &rhs)
        {
            if (this == &rhs)
                return (*this);
            this->_cont = rhs._cont;
            this->_begin = rhs._begin;
            this->_end = rhs._end;
            return (*this);
        }

        void insertionSort()
        {
            unsigned int tmp;
            for (size_t i = 1 ; i < this->_cont.size() ; i++)
            {
                if (this->_cont[i - 1] > this->_cont[i])
                {
                    tmp = this->_cont[i];
                    while (i > 0 && this->_cont[i - 1] > tmp)
                    {
                        this->_cont[i] = this->_cont[i - 1];
                        i--;
                    }
                    this->_cont[i] = tmp;
                }
            }
        }

        T fusionSort(T &_cont1, T &_cont2)
        {
            size_t j = 0;
            size_t k = 0;
            size_t i = 0;
            size_t vsize = _cont1.size() + _cont2.size();
            T _cont(vsize);
            
            for (i = 0 ; j != _cont1.size() && k != _cont2.size() ; i++)
                _cont[i] = (_cont1[j] < _cont2[k]) ? _cont1[j++] : _cont2[k++];
            while (i < vsize)
                _cont[i++] = (k == _cont2.size() ? _cont1[j++] : _cont2[k++]);
            return (_cont);
        }

        void divideToReign()
        {
            size_t middle = this->_cont.size() / 2;
            T _cont1(_cont.begin(), _cont.begin() + middle);
            T _cont2(_cont.begin() + middle, _cont.end());
            PmergeMe <T> c1(_cont1);
            PmergeMe <T> c2(_cont2);
            c1.fordJohnsonSort();
            c2.fordJohnsonSort();
            this->_cont = fusionSort(c1.getCont(), c2.getCont());
        }

        void fordJohnsonSort()
        {
            if (this->_cont.size() <= 32)
                insertionSort();
            else
                divideToReign();
        }

        T &getCont()
        {
            return (this->_cont);
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

        void printCont(int time)const
        {
            std::cout << (time == BEFORE ? "<<< BEFORE >>> :     " : "<<< AFTER >>>  :     ");
            for (size_t i = 0 ; i < this->_cont.size() ; i++)
                std::cout << this->_cont[i] << " ";
            std::cout << std::endl;
        }

        void printChrono(std::string type)const
        {
            std::cout << std::endl << "Time to process a range of " << this->_cont.size();
            std::cout << " elements with " << type << " : ";
            std::cout.precision(6);
            std::cout << this->resultChrono() << " ms" << std::endl;
        }

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

    private:
        std::clock_t _begin;
        std::clock_t _end;
        T _cont;
        PmergeMe();
};

#endif