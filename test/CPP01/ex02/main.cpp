#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "adresse str = " << &str << std::endl;
    std::cout << "adresse strPTR = " << stringPTR << std::endl;
    std::cout << "adresse strREF = " << &stringREF << std::endl;
    std::cout << "valeur str = " << str << std::endl;
    std::cout << "valeur pointee par strPTR = " << *stringPTR << std::endl;
    std::cout << "valeur pointee par strREF = " << stringREF << std::endl;
}