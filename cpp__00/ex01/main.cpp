
#include "./PhoneBook.hpp"

int main()
{
    PhoneBook   phoneBook;
    std::string      command;
    
    while(1 && !std::cin.eof())
    {   
        std::cout << "Enter a command : (ADD | SEARCH | EXIT)\n"; 
        if (!getline(std::cin, command))
        {
            if (std::cin.eof())
            {
                std::cout << "\nEOF detected. Exiting...\n";
                break;
            }
        }
        if (!command.empty() && (!command.compare("EXIT")))    
            break;
        if (!command.empty() && (!command.empty()))
        {
            if (!command.compare("ADD"))
                saveNewContact(phoneBook);
            else if (!command.compare("SEARCH"))
            {
                std::cout << "Search for a Contact \n";
                searchForContact(phoneBook);
            }
            else
                std::cout << " !!!  try with a valid command : ADD | SEARCH | EXIT !!! \n";
        }
    }
    return 0;
}