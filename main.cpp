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
struct Node{
    int info;
    Node* next;
    Node(int info, Node* next ):info(info),next(next){}
    Node(int info):info(info),next(nullptr){}
    Node(){}
    friend ostream& operator<<(ostream& os,Node* h){
        for(Node* t = h;t;t=t->next)os<<t->info<<" ";
        return os;
    }
};
int main()
{
//    Man student1;//student1 - object or class instance
//    student1.age =18;
//    student1.pay = 0;
//    strcpy(student1.name,"Vacy");
//    Man student2("Koly",20,2300);
//    Man student3("Grisha",19,2300);
//    student1.print();
//    student2.print();
//    student3.print();

//    //initialization on declaration
//    printf("\n initialization on declaration\n");
//    Man student4={"Masha",15,0};
//    Man gr[4]= {student1,student2,student3,student4};
//    for(Man x:gr)x.print();
//    Man gr11[3]= {{"s1",15,0},{"s2",19,0},{"s3", 20,2300}};
//    printf("\n gr11 print \n");
//    for(Man x:gr11) x.print();
//   // printf("%s  %d  %d",student1.name, student1.age, student1.pay);
    //tail is head
    Node* head=nullptr;
    Node* node;
    for(int i=0;i<10;i++){
        node = new Node(i,head);
        head = node;
    }
    cout<<head;
    //tail is tail
    Node* head1 = nullptr;
    Node* tail;
    Node* prev;
    for(int i=0;i<10;i++){
        tail = new Node(i);
        if(!head1) prev=head1=tail;
        else prev->next = tail;
        prev = tail;
    }
    cout<<"\n tail is tail\n"<<head1;

    return 0;
}
