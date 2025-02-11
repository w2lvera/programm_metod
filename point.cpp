#include "point.h"

Point::Point()
{
    x=y=0;
}
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
Point::Point(int a)
{
    x=y=a;
}
Point& Point::operator =(int a)
{
    x=y=a;
}
Point& Point::operator =(const Point& p){
    x = p.x;
    y = p.y;
    return *this;
}
ostream& operator <<(ostream& os, const Point& p){
    return os<<p.x<<" "<<p.y;
}
