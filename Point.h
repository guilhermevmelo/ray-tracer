#include <iostream>

class Point {    
public:
    double x, y, z;
    Point();
    Point(double, double);
    Point(double, double, double);
    ~Point();
};

std::ostream& operator<<(std::ostream&, const Point&);

Point operator+(Point, Point);
Point operator-(Point, Point);
Point operator*(Point, double);
Point operator/(Point, double);