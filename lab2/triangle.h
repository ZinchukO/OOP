#ifndef TRIABGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

double cross(const Point& a, const Point& b, const Point& p);
double triangleArea(Point& a, Point& b, Point& c);
bool isDegenerateTriangle(Point& a, Point& b, Point& c);
void checkPointInTriangle(Point& a, Point& b, Point& c, Point& p);

#endif
