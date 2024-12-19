#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _fixedNumber;
        static const int _fracPart = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif