#include <iostream>
using namespace std;


#include <string.h>


class Man{
public:
    char name[20];
    int age;
    int pay;
    void print(){
        printf("%s  %d  %d", name, age, pay);
    }
};
int main()
{
    Man student1;
    student1.age =18;
    student1.pay = 0;
    strcpy(student1.name,"vacy");
    student1.print();
   // printf("%s  %d  %d",student1.name, student1.age, student1.pay);
    return 0;
}
