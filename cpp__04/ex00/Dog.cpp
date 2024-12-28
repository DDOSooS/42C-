#include "./Dog.hpp"

Dog::Dog()
{
    std::cout << "[C]: Dog Object is being Created\n";
    this->_type = "Dog";
}

void Dog::makeSound() const 
{
    std::cout << "this is My sound HHOWW HOWWWWWW !!!!\n";
}

Dog::~Dog()
{
    std::cout << "[D]: Dog Object is being Destroyed\n";
}
