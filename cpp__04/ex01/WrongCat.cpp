#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "\033[32m[Constructor]:\033[0m Wrong Cat Object is being Created \n";
    this->_type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &copy):WrongAnimal(copy)
{
    std::cout << "[Copy Constructor]: WrongCat Object is being Called\n";
}

WrongCat & WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "[WrongCat Assignement Constructor]: WrongCat Object is being Called\n";
    if (this != &copy)
        WrongAnimal::operator=(copy);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Wrong Cat Object is being Destroyed \n";
}