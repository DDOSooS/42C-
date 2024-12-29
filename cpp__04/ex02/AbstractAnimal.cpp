#include "./AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal()
{
    std::cout << "\033[32m[Constructor]:\033[0m AbstractAnimal Object is being Created \n";
    this->_type = "Humain Without Brain";
}

AbstractAnimal::~AbstractAnimal()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m AbstractAnimal Object is being Destroyed \n";
}

std::string AbstractAnimal::getType() const
{
    return (this->_type);
}

void AbstractAnimal::setType(std::string &type) 
{
    this->_type = type;
}
