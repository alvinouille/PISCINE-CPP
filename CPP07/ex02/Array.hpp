#ifndef ARRAY_H
# define ARRAY_H

#include <string>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    public:
        class NotInTabException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Not in the tab (Exception)");
                }
        };

        Array()
        {
            std::cout << "Default constructor" << std::endl;
            this->_array = NULL;
            this->_n = 0;
        }

        Array(unsigned int n) : _n(n)
        {
            std::cout << "Parametric constructor" << std::endl;
            this->_array = new T[_n];
            for (unsigned int i = 0 ; i < n ; i++)
                _array[i] = 0;
        }

        Array(Array const &copy) : _n(copy._n)
        {
            if (copy._array)
            {
                this->_array = new T[copy._n];
                for (unsigned int i = 0 ; i < copy._n ; i++)
                    this->_array[i] = copy._array[i];
            }
            else
                this->_array = NULL;
        }

        Array &operator=(Array const &rhs)
        {
            if (this == &rhs)
                return (*this);
            if (this->_array)
                    delete [] this->_array;
            if (rhs._array)
            {
                this->_array =  new T[rhs._n];
                for (unsigned int i = 0 ; i < rhs._n ; i++)
                    this->_array[i] = rhs._array[i];
            }
            else
                this->_array = NULL;
            this->_n = rhs._n;
            return (*this);
        }

        ~Array()
        {
            if (this->_array)
                delete [] this->_array;
        }

        unsigned int size()const
        {
            return (this->_n);
        }

        T &operator[](unsigned int i)
        {
            if (i >= this->_n)
                throw (NotInTabException());
            else
                return (this->_array[i]);
        }

    private:
        T *_array;
        unsigned int _n;
};

#endif