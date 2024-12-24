#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed
{
    private:
        int _fixedNumber;
        static const int _fracPart = 8;

    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);

        ~Fixed();

        Fixed(const Fixed &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        Fixed& operator=(const Fixed &other);
        bool operator<=(const Fixed &number) const;
        bool operator>=(const Fixed &number) const;
        bool operator==(const Fixed &number) const;
        bool operator<(const Fixed &number) const;
        bool operator>(const Fixed &number) const;
        bool operator!=(const Fixed &number) const;
        Fixed operator/(const Fixed &number) const;
        Fixed operator*(const Fixed &number) const;
        Fixed operator+(const Fixed &number) const;
        Fixed operator-(const Fixed &number) const;
        Fixed& operator++();
        Fixed operator++(int);    
        Fixed& operator--();    
        Fixed operator--(int);
        static Fixed& min(Fixed &fNumber, Fixed &sNumber);
        static const Fixed& min(const Fixed &fNumber, const Fixed &sNumber);
        static Fixed& max(Fixed &fNumber, Fixed &sNumber);
        static const Fixed &max(const Fixed &fNumber, const Fixed &sNumber);
};

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif