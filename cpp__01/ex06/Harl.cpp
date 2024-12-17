#include "./Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info( void )
{
    std::cout << "[ INFO ]\n";     
    std::cout << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn/’t be asking for more\n";
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]\n";      
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]\n";  
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

int hash(std::string level)
{
    if (!level.compare("DEBUG"))
        return (0);
    if (!level.compare("INFO"))
        return (1);
    if (!level.compare("WARNING"))
        return (2);
    if (!level.compare("ERROR"))
        return (3);
    return (4);
}

void    Harl::complain( std::string level )
{
    int hashLevel;
    void (Harl::*mumberFunc[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    hashLevel = hash(level);

    switch (hashLevel)
    {
        case 0:
            (this->*mumberFunc[0])();
            (this->*mumberFunc[1])();
            (this->*mumberFunc[2])();   
            (this->*mumberFunc[3])();
            break;
        case 1:
            (this->*mumberFunc[1])();
            (this->*mumberFunc[2])();   
            (this->*mumberFunc[3])();
            break;
        case 2:
            (this->*mumberFunc[2])();   
            (this->*mumberFunc[3])();
            break;
        case 3:
            (this->*mumberFunc[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
