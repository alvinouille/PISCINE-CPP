

int main(int ac, char **av)
{
    (void)ac;
    std::ifstream ifs(av[1]);
    std::string tmp;
    std::string date;
    std::map<std::string, int> map;
    float value;
    std::string line;

    if (!ifs.is_open())
        return (1);

    while (std::getline(ifs, line))
    {
        std::istringstream iss(line);
        iss >> date;
        iss >> tmp;
        iss >> value;
        map[date] = value;
    }

    std::map<std::string, int>::iterator it;
    for (it = map.begin() ; it != map.end() ; ++it)
    {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}