#include "./Animal.hpp"

Animal::Animal()
{
    std::cout << "[C]: Animal Object is being Created \n";
    this->_type = "Humain Without Brain";
}

Animal::~Animal()
{
    std::cout << "[D]: Animal Object is being Destroyed \n";
}

std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::setType(std::string &type) 
{
    this->_type = type;
}

void Animal::makeSound() const
{
    std::cout << "I'm just an Humain without Brain\n";
}


