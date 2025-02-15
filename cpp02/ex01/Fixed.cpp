#include "./Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "[Default Constructor] : Fixed Default Constructor Called!" << std::endl;
    _fPoint = 0 ;
}

Fixed::Fixed(const int number)
{
    std::cout << "[Int constructor called]\n";
    _fPoint = number << _fractional;
}

Fixed::Fixed(const float  number)
{
    std::cout << "[Float constructor called]\n";
    _fPoint = static_cast<int>(roundf(number * (1 << _fractional)));
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
    this->_fPoint = raw ;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float> (_fPoint) / (1 << _fractional);
}

int Fixed::toInt( void ) const
{
    return _fPoint >> _fractional ;
}

Fixed::~Fixed()
{
    std::cout << "[DeConstructor] : Fixed Deconstructor Called!" << std::endl;
}

std::ostream &operator << (std::ostream &os,  const Fixed &point)
{
    os << point.toFloat();
    return os;
}

