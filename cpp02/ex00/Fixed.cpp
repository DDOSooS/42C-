#include "./Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "[Default Constructor] : Fixed Default Constructor Called!" << std::endl;
    _fPoint = 0 << _fractional;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "[Copy Constructor] : Fixed Copy Constructor Called!" << std::endl;
    *this = copy;
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    std::cout << "[Copy Assignement Constructor] : Fixed Copy Assignement Constructor Called!" << std::endl;
    if (this != &copy)
        this->_fPoint = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return (_fPoint);
}

void Fixed::setRawBits(int const raw)
{
    this->_fPoint = raw << _fractional;
}

Fixed::~Fixed()
{
    std::cout << "[DeConstructor] : Fixed Deconstructor Called!" << std::endl;

}