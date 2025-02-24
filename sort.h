#ifndef SORT_H
#define SORT_H

#endif // SORT_H
template <class T>
void boobleSort(T* a, int n){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0;i<n-1;i++){
            if(a[i]>a[i+1]){
                T t=a[i]; a[i]=a[i+1];a[i+1]=t;
                flag = true;
            }
        }
    }
}
