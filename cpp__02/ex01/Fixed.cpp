#include "./Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedNumber = 0 << this->_fracPart;
}

Fixed::Fixed(const int number)
{
    this->_fixedNumber = number << _fracPart;
}

Fixed::Fixed(const float number) {
    this->_fixedNumber = static_cast<int>(roundf(number * (1 << _fracPart)));
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
    this->_fixedNumber = raw << this->_fracPart;
}


float Fixed::toFloat( void ) const
{
     return static_cast<float>(roundf(this->_fixedNumber) / (1 << _fracPart));
}
int Fixed::toInt( void ) const
{
    return (this->_fixedNumber >> _fracPart);
}

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
    os << number.toFloat(); 
    return os;              
}