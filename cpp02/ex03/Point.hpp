#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:

        Point();
        Point(const Fixed x, const Fixed y);
        Point(const Point &copy);

        Point& operator=(const Point &other);

        Fixed getX() const;
        Fixed getY() const;

        ~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
