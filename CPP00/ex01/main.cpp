#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iomanip>

Contact    create_contact(void)
{
    Contact instance;
    std::string inputStr("");

    std::cout << "WELCOME : You're about to create a new contact my dear friend" << std::endl;
    while (!(instance.set_firstName(inputStr)) || inputStr == "ADD")
    {
        std::cout << "First name : ";
        std::getline(std::cin, inputStr);
    }
    inputStr = "";
    while (!(instance.set_nickname(inputStr)))
    {
        std::cout << "Nickname : ";
        std::getline(std::cin, inputStr);
    }
    inputStr = "";
    while (!(instance.set_phoneNumber(inputStr)))
    {
        std::cout << "Phone number : ";
        std::getline(std::cin, inputStr);
    }
    inputStr = "";
    while (!(instance.set_darkestSecret(inputStr)))
    {
        std::cout << "Darkest secret : ";
        std::getline(std::cin, inputStr);
    }
    std::cout << "A great contact well added to your magnificent phonebook my holy friend" << std::endl;
    return (instance);
}

std::string    formating(std::string str)
{
    std::string nw;

    if (str.size() > 10)
        nw = str.replace(9, str.size() - 9, ".");
    else
        nw = str;
    return (nw);
}


void    print_contact_format(Contact instance)
{
    std::cout << std::setw(10) << instance.get_index() << "|";
    std::cout << std::setw(10) << formating(instance.get_firstName()) << "|";
    std::cout << std::setw(10) << formating(instance.get_nickname()) << "|";
    std::cout << std::setw(10) << formating(instance.get_phoneNumber()) << "|";
    std::cout << std::setw(10) << formating(instance.get_darkestSecret()) << "|" << std::endl;
}

void    print_contact(Contact instance)
{
    std::cout << "first name : " << instance.get_firstName() << std::endl;
    std::cout << "nickname : " << instance.get_nickname() << std::endl;
    std::cout << "phone number : " << instance.get_phoneNumber() << std::endl;
    std::cout << "darkest secret : " << instance.get_darkestSecret() << std::endl;
}

void    search_contact(Phonebook phonebook)
{
    std::string inputStr("");
    int lim_phonebook = 0;
    int valid = 0;
    int i = 0;

    lim_phonebook = Phonebook::get_nbContact();
    if (!lim_phonebook)
        return ;
    for (i = 0 ; i < lim_phonebook ; i++)
        print_contact_format(phonebook.get_contact(i));
    i = 0;
    std::cout << "Enter a valid index (0 to " << lim_phonebook - 1 << ") my love" << std::endl;
    while (!valid)
    {
        getline(std::cin, inputStr);
        if (inputStr.size() != 1)
        {
            std::cout << "Enter a valid number please darling, between 0 and " << lim_phonebook - 1 << std::endl;
            continue;
        }
        i = inputStr[0] - 48;
        if (i >= 0 && i < lim_phonebook)
        {
            print_contact(phonebook.get_contact(i));
            valid = 1;
        }
        else
            std::cout << "Enter a valid number please darling, between 0 and " << lim_phonebook - 1 << std::endl;
    }
}

int main()
{
    std::string inputStr("");
    Phonebook phonebook;

    while (inputStr != "EXIT")
    {
        std::getline(std::cin, inputStr);
        if (inputStr == "ADD")
           phonebook.add_contact(create_contact());
        else if (inputStr == "SEARCH")
            search_contact(phonebook);
        else if (inputStr != "EXIT")
            std::cout << "The only available command are EXIT / ADD / SEARCH my little bug" << std::endl;
        else
            std::cout << "Our journey is coming to an end... Too bad. Have a nice day :)" << std::endl;
    }
}