#pragma once
#include <iostream>

class Fixed
{
    private:
        int _fPoint;
        static const int _fractional = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed & operator=(const Fixed &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
};

