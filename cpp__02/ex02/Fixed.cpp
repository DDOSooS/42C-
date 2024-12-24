#include "./Fixed.hpp"

// Orthodox Canonical Form
Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
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
    // std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called\n";
    *this = copy;
}

// setter & Getters

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
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

//operators 

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
    os << number.toFloat(); 
    return os;              
}

Fixed& Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedNumber = other.getRawBits();
    return *this;
}

bool Fixed::operator<=(const Fixed &number) const
{
    return (this->_fixedNumber <= number.getRawBits());
}

bool Fixed::operator>=(const Fixed &number) const
{
    return (this->_fixedNumber >= number.getRawBits());
}

bool Fixed::operator==(const Fixed &number) const
{
    return (this->_fixedNumber == number.getRawBits());
}

bool Fixed::operator<(const Fixed &number) const
{
    return (this->_fixedNumber < number.getRawBits());
}

bool Fixed::operator>(const Fixed &number) const
{
    return (this->_fixedNumber > number.getRawBits());
}

bool Fixed::operator!=(const Fixed &number) const
{
    return (this->_fixedNumber != number.getRawBits());
}

Fixed Fixed::operator/(const Fixed &number) const
{
    if (number._fixedNumber == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    result._fixedNumber = (this->_fixedNumber << _fracPart) / number.getRawBits();
    return (result);
}
Fixed Fixed::operator*(const Fixed &number) const
{
    Fixed result;
    result._fixedNumber = (this->_fixedNumber * number._fixedNumber) >> _fracPart;
    return (result);
}
Fixed Fixed::operator+(const Fixed &number) const
{
    Fixed result;
    result._fixedNumber = this->_fixedNumber + number.getRawBits();
    return (result);
}

Fixed Fixed::operator-(const Fixed &number) const
{
    Fixed result;
    result._fixedNumber = this->_fixedNumber - number.getRawBits();
    return (result);
}

Fixed& Fixed::operator++()
{
    ++this->_fixedNumber;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++this->_fixedNumber;
    return(temp);
}

Fixed& Fixed::operator--()
{
    --this->_fixedNumber;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --this->_fixedNumber;
    return(temp);
}

 Fixed& Fixed::min(Fixed &fNumber, Fixed &sNumber)
{
    return (fNumber > sNumber)? sNumber:fNumber;
}

 const Fixed& Fixed::min(const Fixed &fNumber, const Fixed &sNumber)
{
    return (fNumber > sNumber)? sNumber:fNumber;
}

 Fixed& Fixed::max(Fixed &fNumber, Fixed &sNumber)
{
    return (fNumber > sNumber)? fNumber:sNumber;
}

 const Fixed& Fixed::max(const Fixed &fNumber, const Fixed &sNumber)
{
    return (fNumber > sNumber)? fNumber: sNumber;
}

