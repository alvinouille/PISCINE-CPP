#include <iostream>
#include <string>
#include <fstream>


void replace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
    std::size_t i = 0;
    std::size_t pos;
    std::string line;

    while (std::getline(ifs, line))
    {
        while (i < line.size())
        {
            pos = line.find(s1.c_str(), i);
            if (pos != std::string::npos  && s1.size() != 0)
            {
                ofs << line.substr(i, pos - i) << s2;
                i = pos + s1.size();
            }
            else
            {
                ofs << line.substr(i, line.size() - i);
                break;
            }
        }
        ofs << std::endl;
        i = 0;
    }
}
int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Error in nb of args" << std::endl;
        return (1);
    }
    std::string outfile;
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream ifs(av[1]);
    if (!ifs.is_open())
    {
        std::cout << "Error in opening the infile" << std::endl;
        return (1);
    }
    outfile = av[1];
    outfile += ".replace";
    std::ofstream ofs(outfile.c_str());
    if (!ofs.is_open())
    {
        std::cout << "Error in creating the outfile" << std::endl;
        return (1);
    }
    replace(ifs, ofs, s1, s2);
    ofs.close();
    ifs.close();
}