#include <iostream>
#include <fstream>
using namespace std;


#include <string.h>
#include <string>;

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
class FrequencyName{
public:
    string name;
    int frequency;
    FrequencyName(string name):name(name),frequency(1){}
    friend ostream& operator<<(ostream& os,FrequencyName& t){return os<<t.name<<" "<<t.frequency;}
    bool operator<(FrequencyName fn){
        return name<fn.name;
    }
    bool operator>(FrequencyName fn){
        return name>fn.name;
    }
    bool operator==(FrequencyName fn){
        return name==fn.name;
    }
    void add(){frequency++;}
};

template <class G>
class Tree{
private:
    struct T{
        G info;
        T* left;
        T* right;
        T(G info):info(info),left(nullptr),right(nullptr){}
        T(G info,T* left, T* right):info(info),left(left),right(right){}
        friend ostream& operator<<(ostream& os,T*& t){return os<<t->info;}
    };

    T* root = nullptr;
    void addEll(T*& h, G x){
        if(!h) h = new T(x);
        else{
            if(x < h->info)addEll(h->left,x);
            if(x > h->info)addEll(h->right,x);
        }
    }
    void action(G x, int h, ostream& os){
        for(int i=0;i<h;i++)os<<" ";
        os<<x<<"\n";

    }
    void LRootR(T* root,int h,ostream& os){
        if(root){
            LRootR(root->left,h+1,os);
            action(root->info,h,os);
            LRootR(root->right,h+1,os);
        }
    }
    void LRootR(T* root,G*& arr){
        if(root){
            LRootR(root->left,arr);
            *arr=root->info; arr++;
            LRootR(root->right,arr);
        }
    }
    void RRootL(T* root,int*& arr){
        if(root){
            RRootL(root->right,arr);
            *arr=root->info; arr++;
            RRootL(root->left,arr);
        }
    }
    T* findNode(T* root, G x){
        if(!root)return root;
        if(root->info == x)return root;
        if(x<root->info)return findNode(root->left,x);
        if(x>root->info)return findNode(root->right,x);
    }

public:
    void add(G x){
        addEll(root,x);
    }
    void sortIncreasing(G* arr){
        LRootR(root, arr);
    }
    void sortDescending(int* arr){
        RRootL(root, arr);
    }
    void addFn(G x){
        T* node = findNode(root,x);
        if(!node) addEll(root,x);
        else {

            (node->info).add();
        }
    }
    friend ostream& operator<<(ostream& os,Tree<G>& tree){
        int h=0;
        tree.LRootR(tree.root,h,os);
        return os;
    }
};
int main()
{
    int arr[]={8,9,11,15,19,20,21,7,3,2,1,5,6,4,13,14,10,12,17,16,18};
    int arr1[21];
   // int* p  = arr1;
    Tree<int> tree;
    for(int x:arr)tree.add(x);
    cout<<tree<<"\n";
    tree.sortIncreasing(arr1);
    for(int x:arr1) cout<<x<<" ";
    tree.sortDescending(arr1);
    cout<<"\n";
    for(int x:arr1) cout<<x<<" ";
    string names[10]={"Norma","Paul","Peter","Georg","Mary","Ann","Peter", "Ann","Norma","Ann"};
    Tree<FrequencyName> fn;
    for(string name:names)
        fn.addFn(name);
    cout<<"\n names\n";
    cout<<fn;
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
    return 0;
}
