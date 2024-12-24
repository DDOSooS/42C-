#include "./Point.hpp"

Point::Point ():_x(0), _y(0){};

Point::Point(const Fixed x, const Fixed y):_x(x),_y(y){};

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}


Point& Point::operator=(const Point &other)
{
    if (this != &other) 
        throw std::logic_error("Assignment not allowed for immutable members.");
    return *this;
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }

Point::~Point(){};


