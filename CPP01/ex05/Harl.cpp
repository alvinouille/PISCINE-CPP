#include "Harl.hpp"

Harl::Harl(void)
{
    tab[0] = &Harl::debug;
    tab[1] = &Harl::info;
    tab[2] = &Harl::warning;
    tab[3] = &Harl::error;
}

Harl::~Harl(void)
{

}

void Harl::debug(void)const
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)const
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning(void)const
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)const
{
    std::cout << "[ERROR] This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0 ; i < 4 ; i++)
    {
        if (lvl[i] == level)
            (this->*tab[i])();
    }
}