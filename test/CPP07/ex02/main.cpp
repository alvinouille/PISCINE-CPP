#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 10
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << ">>> Check of negative index and out of range index" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << ">>> For now, it is all the same value in numbers and mirror" << std::endl;
    for (int i = 0 ; i < MAX_VAL ; i++)
        std::cout << mirror[i] << " - " << numbers[i] << std::endl;

    std::cout << ">>> Because it is deep copy, after changing values of one, it must be different" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand() % 10;
    for (int i = 0 ; i < MAX_VAL ; i++)
        std::cout << mirror[i] << " - " << numbers[i] << std::endl;
    delete [] mirror;//
    return 0;
}