#include <iostream>
#include <fstream>
#include <ios>
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
    friend ostream& operator<<(ostream& os,const Man& m ){
        return os<<m.name<<" "<<m.age<<" "<<m.pay;
    }
    friend istream& operator>>(istream& is, Man& m ){
        //is.get(m.name,20,' ');
        is>>m.name>>m.age>>m.pay;
        return is;
    }

};
int main()
{
    ///////////// output standart /////////////////
    int a=2,b=10;
    double d = 5.67;
    float f = 3.0;
    bool bl = true;
    char c='a';
    cout<<"\nvariables\n";
    cout<<"a = "<<a<<" b = "<<b<<" d = "<<d<<" f = "<<f<<" bl = "<<bl<<" c = "<<c<<"\n";
    int arr[6]{1,2,3,4,5,6};
    cout<<"\narr\n";
    for(int i = 0;i<6;i++) cout<<arr[i]<<" ";
    cout<<"\nstr\n";
    char str[]="i love you";
    cout<<str<<"\n";

    Man student1;//student1 - object or class instance
    student1.age =18;
    student1.pay = 0;
    strcpy(student1.name,"Vacy");
    //initialization on declaration
    Man student2("Koly",20,2300);
    Man student3("Grisha",19,2300);
    cout<<"\nstudent\n";
    cout<<student1<<" "<<student2<<" "<< student3<<endl;
    ////////////////////////////////////////////////
    ///////////// input standart ///////////////////
    cout<<"\n  input a b d f bl c\n";
    cin>>a>>b>>d>>f>>bl>>c;// input 1. leaves the '\n' into cin
    cout<<"a = "<<a<<" b = "<<b<<" d = "<<d<<" f = "<<f<<" bl = "<<bl<<" c = "<<c<<"\n";
    cout<<"\narr\n";
    //for(int i = 0;i<6;i++) cin>>arr[i];
    for(int i = 0;i<6;i++) cout<<arr[i]<<" ";
    cout<<"\nstr\n";
    cin.sync();//removes all from cin
    //cin.ignore(1);//removes '\n' from cin left over from input 1
    //cin.get(str,80,'\n');
    cin.getline(str,80);//takes the '\n' from cin
    cout<<str;
    cout<<"\n student\n";
    //cin.sync();//removes '\n' from cin left over from input 1
    cin>>student1;
    cout<<student1;
    cin.sync();
    cin.getline(str,80);
    cout<<str;
    return 0;
}
