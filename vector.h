#ifndef VECTOR_H
#define VECTOR_H

#endif // VECTOR_H
class Vector

{

private:

  int dx, dy;

public:

  Vector(int dx = 0, int dy = 0) : dx(dx), dy(dy) {}

  Vector(Point a, Point b)

  {

    dx = a.x - b.x;

    dy = a.y - b.y;

  }



  int operator*(Vector &x)

  {

    return this->dx * x.dy - this->dy * x.dx;

  }

};
