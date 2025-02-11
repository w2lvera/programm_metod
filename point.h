#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <fstream>
using namespace std;
class Point
{
public:
    int x;
    int y;
    Point();
    Point(int x,int y);
    Point(int a);
    Point& operator=(const Point& p);
    Point& operator=(const int a);
    friend ostream& operator << (ostream& os, const Point& p );
};

#endif // POINT_H
