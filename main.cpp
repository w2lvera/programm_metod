#include "point.h"
#include "triangle.h"

int main()
{
    Point p1;
    Point p2(1,2);
    Point p3(1);
    cout<<p1<<"\n"<<p2<<"\n"<<p3<<"\n";
    try{
        Triangle t1(p1,p2,p3);
        cout<<t1<<"\n";
        cout<<"\n square = "<<t1.square()<<" perimetr = "<<t1.perimeter()<<endl;
        t1.setP3(Point(5,0));
        t1.setP2(Point(5));

         cout<<"\n new t1\n"<<t1<<"\n square = "<<t1.square()<<" perimetr = "<<t1.perimeter()<<"\ncontains = "<<t1.contains(Point(2,1))<<endl;
    }
    catch(int a){
        switch(a){
            case 0:  cout<<"wrong triangle in constructor\n"; break;
            case 1:  cout<<"wrong point1\n"; break;
            case 2:  cout<<"wrong point2\n"; break;
            case 3:  cout<<"wrong point3\n"; break;
        default: cout <<"unnow error\n";
        }
    }
    return 0;
}
