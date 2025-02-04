#include <iostream>
using namespace std;


#include <string.h>


class Man{
public:
    //class data
    char name[20]="";
    int age=0;
    int pay=0;
    //constructor
    Man(){}//default constructor
    Man(const char* n, int a,int p){//constructor with parameters
        strcpy(name,n);
        age = a;
        pay = p;
    }
    Man(Man& m){
        strcpy(name,m.name);
        age = m.age;
        pay = m.pay;
    }
    //class metod
    void print(){
        printf("%10s   %4d  %d\n", name, age, pay);
    }
};
int main()
{
    Man student1;//student1 - object or class instance
    student1.age =18;
    student1.pay = 0;
    strcpy(student1.name,"Vacy");
    Man student2("Koly",20,2300);
    Man student3("Grisha",19,2300);
    student1.print();
    student2.print();
    student3.print();

    //initialization on declaration
    printf("\n initialization on declaration\n");
    Man student4={"Masha",15,0};
    Man gr[4]= {student1,student2,student3,student4};
    for(Man x:gr)x.print();
    Man gr11[3]= {{"s1",15,0},{"s2",19,0},{"s3", 20,2300}};
    printf("\n gr11 print \n");
    for(Man x:gr11) x.print();
   // printf("%s  %d  %d",student1.name, student1.age, student1.pay);
    return 0;
}
