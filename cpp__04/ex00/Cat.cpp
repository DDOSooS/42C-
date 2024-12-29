#include "./Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << "\033[32m[Constructor]:\033[0m Cat Object is being Created\n";
}

Cat::Cat(const Cat &copy):Animal(copy)
{
    std::cout << "[Copy Constructor]: Cat Object is being Called\n";
}

Cat & Cat::operator=(const Cat &copy)
{
    std::cout << "[Copy Assignement Constructor]: Cat Object is being Called\n";
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "this is My sound MEOOOOOOOOOOOOOO !!!!\n";
}

Cat::~Cat()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Cat Object is being Destroyed\n";
}