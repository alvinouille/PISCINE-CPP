#include "iter.hpp"

int main()
{
    size_t size = 5;
    float tabF[5] = {0.1f, 1.0f, 2.45f, 3.25f, 10.0042f};
    int tabI[5] = {0, 1, 2, 3, 4};
    std::string tabS[5] = {"salade", "viennoiseries", "mayo", "parapluie", "pailles"};
    
    std::cout << "- - - FLOAT - - -" << std::endl;
    iter<float, size_t>(tabF, size, incrementation<float>);

    std::cout << std::endl << "- - - INT - - -" << std::endl;
    iter<int, size_t>(tabI, size, incrementation<int>);

    std::cout << std::endl << "- - - STRING - - -" << std::endl;
    iter<std::string, size_t>(tabS, size, incrementation<std::string>);
}