#include "Sierpinski.h"

Sierpinski::Sierpinski(Point a, Point b, Point c) {
    vertexes[0] = a;
    vertexes[1] = b;
    vertexes[2] = c;

    derived[0] = (a + b + c) / 3;
    derived[1] = (derived[0] - vertexes[rand() % 3]) / 2;
}   

Sierpinski::~Sierpinski() {
}