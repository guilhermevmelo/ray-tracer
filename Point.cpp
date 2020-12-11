#include "Point.h"


Point::Point()
    :x(0), y(0), z(0) {}

Point::Point(double x, double y)
    :x(x), y(y), z(0) {}

Point::Point(double x, double y, double z)
    :x(x), y(y), z(z) {}

Point::~Point() {}

std::ostream& operator<<(std::ostream& os, const Point &p) {
    return os << "[" << p.x << ", " << p.y << ", " << p.z << "]";
};

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
};

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
};

Point operator*(Point p, double b) {
    return Point(p.x * b, p.y * b, p.z * b);
};

Point operator/(Point p, double b) {
    return Point(p.x / b, p.y / b, p.z / b);
};