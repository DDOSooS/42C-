#include "./Dog.hpp"

Dog::Dog()
{
    std::cout << "\033[32m[Constructor]:\033[0m Dog Object is being Created\n";
    this->_type = "Dog";
}

Dog::Dog(const Dog &copy):Animal(copy)
{
    std::cout << "[Copy Constructor]: Dog Object is being Called\n";
}

Dog & Dog::operator=(const Dog &copy)
{
    std::cout << "[Dog Assignement Constructor]: Dog Object is being Called\n";
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}


void Dog::makeSound() const 
{
    std::cout << "this is My sound HHOWW HOWWWWWW !!!!\n";
}

Dog::~Dog()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Dog Object is being Destroyed\n";
}
