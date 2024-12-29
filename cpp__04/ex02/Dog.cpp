#include "./Dog.hpp"

Dog::Dog()
{
    std::cout << "\033[32m[Constructor]:\033[0m Dog Object is being Created\n";
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
    std::cout << "[Copy Constructor]: Dog Object is being Called\n";
    this->_brain = copy.getBrain();
}

Dog & Dog::operator=(const Dog &copy)
{
    std::cout << "[Dog Assignement Constructor]: Dog Object is being Called\n";
    if (this != &copy)
    {
        this->_brain = copy.getBrain();
        this->_type = copy.getType();
    }
    return (*this);
}

Brain * Dog::getBrain() const
{
    return (this->_brain);
}

void Dog::setBrain(Brain *brain)
{
    this->_brain = brain;
}

void Dog::makeSound() const 
{
    std::cout << "this is My sound HHOWW HOWWWWWW !!!!\n";
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "\033[31m[DeConstructor]:\033[0m Dog Object is being Destroyed\n";
}
