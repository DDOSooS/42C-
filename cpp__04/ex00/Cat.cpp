#include "./Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    std::cout << "[C]: Cat Object is being Created\n";
}

void Cat::makeSound() const
{
    std::cout << "this is My sound MEOOOOOOOOOOOOOO !!!!\n";
}

Cat::~Cat()
{
    std::cout << "[D]: Cat Object is being Destroyed\n";
}