
#include "./Fixed.hpp"

int main( void ) {
Fixed a;
const Fixed k;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b / k << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}