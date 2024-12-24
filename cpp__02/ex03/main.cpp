
#include "./Point.hpp"

float Abs(float number)
{
    return ((number < 0) ? -number : number);
}

float area(Point p1, Point p2, Point p3) 
{
    float term1 = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat());
    float term2 = p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat());
    float term3 = p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
    
    float sum = term1 + term2 + term3;
    return (0.5f * Abs(sum));
}

Fixed crossProduct(Point p, Point p1, Point p2)
{
    return ((p.getY() - p1.getY()) * (p2.getX() - p1.getX()) - 
            (p.getX() - p1.getX()) * (p2.getY() - p1.getY()));
}

bool inLineE(Point p1, Point p2, Point p3)
{
    if (p3.getX() >= std::min(p2.getX(), p1.getX()) && 
        p3.getX() <= std::max(p2.getX(), p1.getX()) &&
        p3.getY() >= std::min(p2.getY(), p1.getY()) && 
        p3.getY() <= std::max(p2.getY(), p1.getY()))
    {
        Fixed cross = crossProduct(p3, p1, p2);
        return (Abs(cross.toFloat()) < 0.000001f);
    }
    return false; 
}

bool isInsideTriangle(Point a, Point b, Point c, Point point)
{
    if (inLineE(a, b, point) || inLineE(a, c, point) || inLineE(b, c, point))
        return (0);
    float A1 = area(a, b, point);
    float A2 = area(a, c, point);
    float A3 = area(c, b, point);
    float GA = area(a, b, c);


    std::cout << "A1: " << A1 << "\n";
    std::cout << "A2: " << A2 << "\n";
    std::cout << "A3: " << A3 << "\n";
    std::cout << "GA: " << GA << "\n";
    std::cout << "Sum of A1 + A2 + A3: " << A1 + A2 + A3 << "\n";

    return Abs((A1 + A2 + A3) - GA) < 1e-6;
}

int main(void)
{
    const Point a(Fixed(1), Fixed(1));
    const Point b(Fixed(7), Fixed(1));
    const Point c(Fixed(4), Fixed(6));

    const Point d(Fixed(1), Fixed(1));      
        
    if (isInsideTriangle(a, b ,c ,d))
        std::cout << "Point is Inside the Tria, b, c,Angle\n";
    else
        std::cout << "Point is NOT Inside the Triangle\n";
    
    return 0;
}

