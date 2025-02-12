#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "\033[32m[Constructor]:\033[0m Wrong Animal Object is beig Created \n";
    this->_type = "Wrong Humain Without Brain";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "[Copy Constructor]: Wrong Animal Object is beig Called \n";
    this->_type = copy.getType();
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "[Copy Assignement Constructor]: Wrong Animal Object is beig Called \n";
    if (this != &copy)
        this->_type = copy.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Wrong Animal Object is beig Destroyed \n";
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