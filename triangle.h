#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "vector.h"
class Triangle
{
private:
    Point p1;
    Point p2;
    Point p3;
    int vect(int x1, int y1, int x2, int y2);
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    Triangle(const Triangle& p);
    double square();
    double perimeter();
    int contains(const Point& p);
    friend ostream& operator<<(ostream& os, const Triangle& t);
    void setP1(const Point& p);
    void setP2(const Point& p);
    void setP3(const Point& p);
    Point getP1();
    Point getP2();
    Point getP3();
};

#endif // TRIANGLE_H
