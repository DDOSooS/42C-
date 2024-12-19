#include "./Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedNumber = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedNumber = other.getRawBits();
    return *this;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called\n";
    *this = copy;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return (this->_fixedNumber);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedNumber = raw;
}
