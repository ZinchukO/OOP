#include <iostream>
#include <cmath>
#include "triangle.h"

double cross(Point& a, Point& b, Point& p) {
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

double triangleArea(Point& a, Point& b, Point& c) {
    return std::abs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2.0);
}

bool isDegenerateTriangle(Point& a, Point& b, Point& c) {
    return triangleArea(a, b, c) < 1e-9;
}

void checkPointInTriangle(Point& a, Point& b, Point& c, Point& p) {
    double d1 = cross(a, b, p);
    double d2 = cross(b, c, p);
    double d3 = cross(c, a, p);

    if ((d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0)) {
        if (std::abs(d1) < 1e-9 || std::abs(d2) < 1e-9 || std::abs(d3) < 1e-9)
            std::cout << "Point lies on border\n";
        else
            std::cout << "Point is inside\n";
    } else {
        std::cout << "Point is beside\n";
    }
}
