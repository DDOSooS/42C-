#include "./Point.hpp"

#include <iostream>

int main( void )
{

    Point p1(Fixed(0), Fixed(0));
    Point p2(Fixed(5 ), Fixed(0));
    Point p3(Fixed(2.5f), Fixed(5));
    Point point(Fixed(5), Fixed(0));
    std::cout << bsp(p1, p2, p3, point);
    return 0;
}