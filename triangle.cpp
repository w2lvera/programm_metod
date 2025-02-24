#include "triangle.h"
#include <math.h>

Triangle::Triangle()
{
    p1=p2=p3=0;
}
Triangle::Triangle(Point p1, Point p2, Point p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    if(!square()) throw(0);
}
Triangle::Triangle(const Triangle& p)
{
    p1 = p.p1;
    p2 = p.p2;
    p3 = p.p3;
}
Triangle& Triangle::operator =(const Triangle& p){
    p1 = p.p1;
    p2 = p.p2;
    p3 = p.p3;
    return *this;
}
bool Triangle::operator >( Triangle& t){
    return this->square()>t.square();
}
double Triangle::square(){
    double s = fabs((p1.x-p3.x)*(p2.y-p3.y)-(p1.y-p3.y)*(p2.x-p3.x))*0.5;
    return s;
}
double Triangle::perimeter()
{
    double l1 = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    double l2 = sqrt((p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y));
    double l3 = sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y));
    return l1+l2+l3;
}
int Triangle::contains(const Point& o)
{
    //Вычисляем косые произведения.
    //We calculate skew products.


    int p = vect(p1.x - o.x, p1.y - o.y, p2.x - p1.x, p2.y - p1.y);
    int q = vect(p2.x - o.x, p2.y - o.y, p3.x - p2.x, p3.y - p3.y);
    int r = vect(p3.x - o.x, p3.y - o.y, p1.x - p3.x, p1.y - p3.y);

  //  p = vect(xa - xo, ya - yo, xb - xa, yb - ya);

  //  q = vect(xb - xo, yb - yo, xc - xb, yc - yb);

  //  r = vect(xc - xo, yc - yo, xa - xc, ya - yc);
   // Если все повороты имеют один знак, то точка О лежит внутри треугольника.
   // If all rotations have the same sign, then point O lies inside the triangle.
    Vector OA(o,p1); Vector AB(p1,p2);

      Vector OB(o,p2); Vector BC(p2,p3);

      Vector OC(o,p3); Vector CA(p3,p1);

  return    (((OA*AB <= 0) && (OB*BC <= 0) && (OC*CA <= 0)) ||

            ((OA*AB >= 0) && (OB*BC >= 0) && (OC*CA >= 0)));
   // return ((p <= 0 && q <= 0 && r <= 0) || (p >= 0 && q >= 0 && r >= 0));

}
ostream& operator<<(ostream& os, const Triangle& t){
    return os<<"triangle\n"<<t.p1<<" "<<t.p2<<" "<<t.p3<<endl;
}
void Triangle::setP1(const Point& p)
{
    Point help(p1);
    this->p1 = p;
    if(!square()) {
        p1 = help;
        throw(1);
    }
}

void Triangle::setP2(const Point& p)
{
    Point help(p2);
    this->p2 = p;
    if(!square()) {
        p2 = help;
        throw(2);
    }
}
void Triangle::setP3(const Point& p)
{
    Point help(p3);
    this->p3 = p;
    if(!square()) {
        p3 = help;
        throw(3);
    }
}
Point Triangle::getP1(){
    return p1;
}
Point Triangle::getP2(){
    return p2;
}
Point Triangle::getP3(){
    return p3;
}
int Triangle::vect(int x1, int y1, int x2, int y2)
{

    return x1 * y2 - y1 * x2;

}


//Точка О лежит внутри треугольника ABC, если все три поворота OAB, OBC, OCA одновременно левые или правые.



















