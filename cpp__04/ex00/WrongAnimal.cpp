#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "[C]: Wrong Animal Object is beig Created \n";
    this->_type = "Wrong Humain Without Brain";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[D]: Wrong Animal Object is beig Destroyed \n";
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::setType(std::string &type) 
{
    this->_type = type;
}

 void WrongAnimal::makeSound() const
{
    std::cout << "this is my SOUND: HAHA HOHO HIHI 3A3A\n";
}