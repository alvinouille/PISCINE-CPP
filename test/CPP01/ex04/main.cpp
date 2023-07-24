#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int ac, char **av)
{
    std::string line;
    std::string outfile;
    std::size_t i = 0;
    std::size_t pos;

    if (ac != 4)
        return (1);
    std::string s1(av[2]);
    std::string s2(av[3]);
    std::ifstream ifs(av[1]);
    outfile = av[1];
    outfile += ".replace";
    std::ofstream ofs(outfile.c_str());
    if (!ifs.is_open())
    {
        std::cout << "Error in opening the file" << std::endl;
        return (1);
    }
    while (std::getline(ifs, line))
    {
        while (i < line.size())
        {
            pos = line.find(s1.c_str(), i);
            if (pos != std::string::npos)
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
        i = 0;
    }
    ofs.close();
    ifs.close();

}