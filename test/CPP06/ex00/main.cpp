#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter scal;

    scal.convert("a");
    scal.convert("42");
    scal.convert("0.042f");
    scal.convert("0.02536521");
}