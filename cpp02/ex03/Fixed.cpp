#include "./Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "[Default Constructor] : Fixed Default Constructor Called!" << std::endl;
    _fPoint = 0 ;
}

Fixed::Fixed(const int number)
{
    // std::cout << "[Int constructor called]\n";
    _fPoint = number << _fractional;
}

Fixed::Fixed(const float  number)
{
    // std::cout << "[Float constructor called]\n";
    _fPoint = static_cast<int>(roundf(number * (1 << _fractional)));
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "[Copy Constructor] : Fixed Copy Constructor Called!" << std::endl;
    *this = copy;
}

Fixed & Fixed::operator=(const Fixed &copy)
{
    // std::cout << "[Copy Assignement Constructor] : Fixed Copy Assignement Constructor Called!" << std::endl;
    if (this != &copy)
        this->_fPoint = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called\n";
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
    // std::cout << "[DeConstructor] : Fixed Deconstructor Called!" << std::endl;
}

/* =================== overloading Operators ========================== */

std::ostream &operator << (std::ostream &os,  const Fixed &point)
{
    os << point.toFloat();
    return os;
}


Fixed Fixed::operator ++() 
{
    this->_fPoint++;
    return *this;
}

Fixed  Fixed::operator ++(int) 
{
    Fixed tmp = *this;
    this->_fPoint++;
    return (tmp);
}

Fixed Fixed::operator --()
{
    this->_fPoint--;
    return (*this);
}

Fixed Fixed::operator --(int)
{
    Fixed tmp;

    this->_fPoint--;
    return tmp;
}

Fixed  Fixed::operator+(const Fixed &other) const
{
    Fixed tmp;

    tmp.setRawBits(this->_fPoint + other.getRawBits());
    return tmp;
}

Fixed  Fixed::operator-(const Fixed &other ) const
{
    Fixed tmp;

    tmp.setRawBits(this->_fPoint - other.getRawBits());
    return tmp;
}

Fixed  Fixed::operator*(const Fixed &other) const
{
    Fixed tmp;

    tmp.setRawBits((this->_fPoint * other.getRawBits()) >> this->_fractional);
    return tmp;
}

Fixed  Fixed::operator/(const Fixed &other) const
{
    Fixed tmp;

    if (other.getRawBits())
        tmp.setRawBits((this->getRawBits() << _fractional) / other.getRawBits());
    return tmp;
}

/* ================   comparision operator   ===================*/

bool Fixed::operator <(const Fixed &other) 
{
    if (this != &other)
        return (this->_fPoint < other.getRawBits());
    return (0);
}

bool Fixed::operator >(const Fixed &other) 
{
    if (this != &other)
        return (this->_fPoint > other.getRawBits());
    return (0);
}

bool Fixed::operator >=(const Fixed &other) 
{
    if (this != &other)
        return (this->_fPoint >= other.getRawBits());
    return (0);
}

bool Fixed::operator <=(const Fixed &other) 
{
    if (this != &other)
        return (this->_fPoint <= other.getRawBits());
    return (0);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b) 
{
    return ((a.getRawBits() < b.getRawBits()) ? a: b);
}

Fixed & Fixed::min( Fixed &a,  Fixed &b) 
{
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b) 
{
    return ((a.getRawBits() > b.getRawBits()) ?  a : b);
}

Fixed & Fixed::max( Fixed &a,  Fixed &b) 
{
    return ((a.getRawBits() > b.getRawBits()) ?  a:b);
}
