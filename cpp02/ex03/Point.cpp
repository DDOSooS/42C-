#include "./Point.hpp"

Point::Point() : _x(0), _y(0)
{
    // std::cout << "[Default Constructor] : Point Default Constructor Called!" << std::endl;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
    // std::cout << "[Constructor] : Point Constructor Called!" << std::endl;
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
    // std::cout << "[Copy Constructor] : Point Copy Constructor Called!" << std::endl;
}

Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}

Point &Point::operator=(const Point &other)
{
    (void) other;
    return *this;
}

Point::~Point()
{
    // std::cout << "[DeConstructor] : Point Deconstructor Called!" << std::endl;
}

float Abs(float num)
{
    return (num > 0 ? num: -num);
}

float area(Point const p , Point const a, Point const b)
{
    return (Abs(
            ((p.getX() * (a.getY() - b.getY())) +
            (a.getX() * (b.getY() - p.getY())) + 
            (b.getX() * (p.getY() - a.getY()))).toFloat()
            ) 
            / 2.0f) ;
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    float totalArea = area(a, b,c);
    float area1 = area(point, a, b);
    float area2 = area(point, a, c);
    float area3 = area(point, b, c);

    if (!area1 || !area2 || !area3 || area1 + area2 + area3 != totalArea)
        return false;
    return true;
}
