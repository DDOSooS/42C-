
#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fPoint;
        static const int _fractional = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed &copy);

        Fixed & operator=(const Fixed &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool    operator <(const Fixed &other);
        bool    operator >(const Fixed &other);
        bool    operator <=(const Fixed &other);
        bool    operator >=(const Fixed &other);

        Fixed operator +(const Fixed &other) const;
        Fixed operator -(const Fixed &other) const;
        Fixed operator *(const Fixed &other) const;
        Fixed operator /(const Fixed &other) const;

        Fixed operator ++() ;
        Fixed operator ++(int) ;
        Fixed operator --();
        Fixed operator --(int);

        static  Fixed & min(Fixed &a, Fixed &b) ;
        static const Fixed & min(const Fixed &a, const Fixed &b) ;
        static  Fixed & max(Fixed &a, Fixed &b) ;
        static const Fixed & max(const Fixed &a, const Fixed &b) ;

        ~Fixed();
    };
std::ostream &operator<<(std::ostream &os,  const Fixed &point);
