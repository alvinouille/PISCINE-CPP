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
#include <utility>
#include <cmath>

# define BEFORE 0
# define AFTER 1

class PmergeMe
{
    private:
        std::vector<int> _list;
        std::vector<int> res;
        int ij;
        int flag;
        PmergeMe();
        int digitValue(std::string value)
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
        int jacobsthal[15];

    public:
        PmergeMe(int size, char **nb)
        {
            for (int i = 1 ; i < size ; i++)
            {
                if (std::string(nb[i]) == "")
                    throw (std::exception());
                int value = digitValue(std::string(nb[i]));
                if (value == -1)
                    throw (std::exception());
                this->_list.push_back(value);
            }
            jacobsthal[0] = 0;
            jacobsthal[1] = 1;
            jacobsthal[2] = 1;
            jacobsthal[3] = 3;
            jacobsthal[4] = 5;
            jacobsthal[5] = 11;
            jacobsthal[6] = 21;
            jacobsthal[7] = 43;
            jacobsthal[8] = 85;
            jacobsthal[9] = 171;
            jacobsthal[10] = 341;
            jacobsthal[11] = 683;
            jacobsthal[12] = 1365;
            jacobsthal[13] = 2731;
            jacobsthal[14] = 5641;
            jacobsthal[15] = 10923;
            this->ij = 0;
            this->flag = 0;
        }
        ~PmergeMe() {}
        PmergeMe &operator=(PmergeMe const &rhs)
        {
            if (this == &rhs)
                return (*this);
            return (*this);
        }

        std::vector<int> getter()
        {
            return this->_list;
        }

        std::vector<int> launcher(void)
        {
            std::vector<std::pair<int, int> > newTab;
            fordJohnsonSort(newTab);
            return (this->res);
        }

        int searchingValue(std::vector<std::pair<int, int> > tab, int value)
        {
            for (size_t i = 0 ; i < tab.size() ; i++)
            {
                if (tab[i].first == value)
                    return tab[i].second;
            }
            return -1;
        }

        int dichotomicSearch(std::vector<int> tab, int begin, int end, int eC)
        {
            if (begin == end)
                return (eC <= tab[begin] ? begin : begin + 1);
            int midI = floor((end - begin) / 2);
            if (eC < tab[begin + midI])
                return (dichotomicSearch(tab, begin, begin + midI, eC));
            else
                return (dichotomicSearch(tab, begin + midI + 1, end, eC));
        }

        void fordJohnsonSort(std::vector<std::pair<int, int> > tab)
        {
            std::vector<std::pair<int, int> > newTab;
            int a, b, toInsert;
            if (flag == 0)
            {
                for (size_t i = 0 ; i < this->_list.size(); i += 2)
                {
                    a = (this->_list[i] > this->_list[i + 1] ? this->_list[i] : this->_list[i + 1]);
                    b = (this->_list[i] > this->_list[i + 1] ? this->_list[i + 1] : this->_list[i]);
                    if (_list.size() % 2 == 1 && i == this->_list.size() - 1)
                    {
                        a = this->_list[i];
                        b = -1;
                    }
                    std::pair<int, int> newPair(a, b);
                    newTab.push_back(newPair);
                }
                flag++;
            }
            else
            {
                for (size_t i = 0 ; i < tab.size() ; i += 2)
                {
                    a = (tab[i].first > tab[i + 1].first ? tab[i].first : tab[i + 1].first);
                    b = (tab[i].first > tab[i + 1].first ? tab[i + 1].first: tab[i].first);
                    if (tab.size() % 2 == 1 && i == tab.size() - 1)
                    {
                        a = tab[i].first;
                        b = -1;
                    }
                    std::pair<int, int> newPair(a, b);
                    newTab.push_back(newPair);
                }
                flag++;
            }
            if (newTab.size() == 1)
            {
                this->res.push_back(newTab[0].second);
                this->res.push_back(newTab[0].first);
                return ;
            }
            else
                fordJohnsonSort(newTab);

            this->res.insert(res.begin(), searchingValue(newTab, res[0]));
            int x = res[0];

            // for (int i = jacobsthal[ij] ; i >= jacobsthal[ij] - ij ; i--)
            // {
            //     toInsert = searchingValue(newTab, res[i]);
            //     res.insert(res.begin() + dichotomicSearch(this->res, 0, res.size() - 1, toInsert), toInsert);
            //     std::cout << ij << ", jacob = " << jacobsthal[ij] << " -> to insert : " << toInsert << " at " << dichotomicSearch(this->res, 0, res.size() - 1, toInsert) << std::endl;
            // }


            for (int i = newTab.size() - 1 ; i >= 0 ; i--)
            {
                toInsert = newTab[i].second;
                if (toInsert == x)
                    continue;
                res.insert(res.begin() + dichotomicSearch(this->res, 0, res.size() - 1, toInsert), toInsert);
                std::cout << "to insert : " << toInsert << " at " << dichotomicSearch(this->res, 0, res.size() - 1, toInsert) << std::endl;
            }
        }



};

#endif