// classHelp11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Man.h"
#include <string.h>
#include<stdlib.h>
bool compInt(int a, int b) { return a > b; }
//bool compMan(Man a, Man b) 
//{ return a.pay > b.pay; }
template <class T>
void boobleSort(T* a, int n) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                T k = a[i];
                a[i] = a[i -1];
                a[i - 1] = k;
                flag = 1;
            }
        }
    }
}
int main()
{
    Man student("Vacy",19,3300);
    Man student1("Koly", 19, 0);
    Man gr[8] = { {"Ivanov",19,3300},{"Petrov",19,3300},{"Pushkin",19,3300},
        {"Kalinin",19,3300},{"Abramov",19,3300},{"Sidorov",19,3300},
        {"Ivanova",19,3300},{"Petrova",19,3300} };
    for (Man m : gr) {
        m.print();
    }
    boobleSort(gr, 8);
    std::cout << "\n after sort\n";
    for (Man m : gr) {
        m.print();
    }
    // bool b = student.compMan( student1);
    student = student1=student2;
    //std::cout << "\n compMan " << b << "\n";
    /*int a;
    int b1;
    b=a > b1;*/

   // Man prepod;
    /*student.age = 19;
    student.pay = 3300;
    strcpy_s(student.name,50, "Vacy");*/
    //prepod.age = 55;
   // prepod.pay = 40000;
   // strcpy_s(prepod.name, 50, "Vacy");
   // std::cout << student;
   // student.print();
   //prepod.print();
    //std::cout << student.name << " " << student.age << " " << student.pay << "\n";
   // std::cout << prepod.name << " " << prepod.age << " " << prepod.pay << "\n";
    
}
// Student - объект типа Man или экземпляр класса Man или instance of Man
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
