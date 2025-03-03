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
        Fixed(const Fixed &copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

    std::ostream& operator<<(std::ostream& os, const Fixed& number) ;
#endif

// < > <= >= == != + - * / ++d ++d --d --d 