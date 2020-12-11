#include <cstdlib>
#include "Point.h"

class Sierpinski {
public:
    Point derived[3], vertexes[3];

    Sierpinski(Point, Point, Point);
    ~Sierpinski();
};
