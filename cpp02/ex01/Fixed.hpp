
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



        ~Fixed();
    };
std::ostream &operator<<(std::ostream &os,  const Fixed &point);
