#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "[C]: Wrong Cat Object is being Created \n";
    this->_type = "Wrong Cat";
}

WrongCat::~WrongCat()
{
    std::cout << "[D]: Wrong Cat Object is being Destroyed \n";
}