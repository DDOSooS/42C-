#include "./Harl.hpp"

Harl::Harl()
{
    std::cout << "[CONSTRUCTOR] : Harl object is being Created \n";
}

Harl::~Harl()
{
    std::cout << "[DECONSTRUCTOR] : Harl object is being Destroyed \n" ;
}

void Harl::info()
{
    std::cout << "[INFO] : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::debug()
{
    std::cout << "[DEBUG] : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::warning()
{
    std::cout << "[WARNING] : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "[ERROR] : This is unacceptable! I want to speak to the manager now.\n";
}

int getLevel(std::string &level)
{
    int i;
    std::string levels[4] = 
    {
        "INDO",
        "DEBUG",
        "WARNING",
        "ERROR"
    };
    for ( i = 0; i < 4; i++)
    {
        if (!level.compare(levels[i]))
            break;
    }
    return (i);
}

void Harl::complain(std::string level)
{
    int index;

    void (Harl::*complainLevel[4])() =
    {
        &Harl::info, 
        &Harl::debug,
        &Harl::warning,
        &Harl::error
    };
    index = getLevel(level);
    if (index > 3)
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        return ; 
    }
    (this->*complainLevel[index])();
}