#include <iostream>
using namespace std;


const int m = 10;
void createHashTable(int hashTable[][2],int in[6][2],int n){
    int j;
    for(int i=0;i<m;i++)hashTable[i][0] = -1;
    for(int i=0;i<n;i++){
        int i1 = 0;
        int k = in[i][0];
        while(true){
            j = (k+i1*i1)%m;
            if(hashTable[j][0]== -1)break;
            i1++;
        }
        hashTable[j][0] = k;
        hashTable[j][1] = in[i][1];
    }
}
int search(int hashTable[][2], int key){
    int i1 = 0;
    int j;
    while(true){
        j = (key+i1*i1)%m;
        if(hashTable[j][0]== key)break;
        i1++;
    }

   return  hashTable[j][1];
}
int main()
{
    int in[6][2]={2002,0,1914,1,1939,2,1945,3,1953,4,1944,5};
    for(int i=0;i<6;i++){
        cout<<in[i][0]<<" "<< in[i][1]<<"\n";
    }
    cout<<"\n";
    int hashTable[m][2];
    createHashTable(hashTable,in,6);
    for(int i=0;i<m;i++){
        cout<<hashTable[i][0]<<" "<< hashTable[i][1]<<"\n";
    }
    int index = search(hashTable,1944);
    cout<<"index = "<<index;
    return 0;
}
