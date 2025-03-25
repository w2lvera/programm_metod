#include <iostream>
#include <fstream>
using namespace std;


#include <string.h>
#include "sort.h"
#include "sortComp.h"

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
    Man& operator=(const Man& m){
        strcpy(name,m.name);
        age = m.age;
        pay = m.pay;
        return *this;
    }

    bool operator<(const Man& m){
        return strcmp(name,m.name)<0;
    }
    bool operator>(const Man& m){
        return strcmp(name,m.name)>0;
    }
    //class metod
    friend ostream& operator<<(ostream& os, const Man m){
        return os<<m.name<<" "<<m.age<<" "<<m.pay;
    }
    static bool compAge(Man& m1,  Man& m2){
        return m1.age<m2.age;
    }
    static bool compPay(Man& m1,  Man& m2){
        return m1.pay<m2.pay;
    }
    static int compAgeQsort(const void* a,const void* b){
        Man* m1 = (Man*)a;
        Man* m2 = (Man*)b;
        return m1->age-m2->age;
    }
};
template <class T>
void printArr(T*a,int n){
    for(int i = 0;i<n;i++)
        std::cout<<a[i]<<" ";
}
bool compInt(int& a, int& b){
    return a<b;
}
int compIntQsort(const void* a,const void* b){
    int* ap =(int*)a;
    int* bp = (int*)b;
    return *ap - *bp;
}
int main()
{
//    Man gr11[4]= {{"s2",25,5000},{"s1",19,10},{"s0", 21,2305},{"a0", 20,2300}};
//    cout<<"\n gr11 print \n";
//    for(Man x:gr11) cout<<x<<"\n";
//    insert(gr11,4,Man::compPay);
//    qs(gr11,0,3,Man::compAge);
//    qsort(gr11,4,sizeof(Man),Man::compAgeQsort);
 //   qs(gr11,0,3);
//   insert(gr11,4);
//    cout<<"\n gr11 print after sort\n";
//    for(Man x:gr11) cout<<x<<"\n";
    int arr[8]={42,55,12,44,94,18,6,67};
    //shell(arr,8,compInt);
   // qs(arr,0,7,compInt);
    qsort(arr,8,sizeof(int),compIntQsort);
    printArr(arr,8);
    return 0;
}
