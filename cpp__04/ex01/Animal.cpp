#include "./Animal.hpp"

Animal::Animal()
{
    std::cout << "\033[32m[Constructor]:\033[0m Animal Object is being Created \n";
    this->_type = "Humain Without Brain";
}

Animal::Animal(const Animal &copy)
{
    std::cout << "[Copy Constructor] is being Called\n";
    if (this != &copy)
        this->_type = copy.getType();
}

Animal & Animal::operator=(const Animal &copy)
{
    std::cout << "[Copy Assignement Constructor] is being Called\n";
    if (this != &copy)
    {
        Animal(copy);

            // this->_type = copy.getType();
        
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Animal Object is being Destroyed \n";
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
