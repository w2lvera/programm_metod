#pragma once
#include <fstream>
using namespace std;
class Man
{
private:
	char name[50];
	int age;
	int pay;
public://Man student("Vacy", 19, 3300);
	Man(const char*, int, int);
	Man();
	Man(const Man& m);
	~Man();
	void setName(const char* name);
	void setAge(int age);
	int getAge();
	bool compMan(Man b);
	bool operator >(const Man& b);
	Man& operator = (const Man& b);
	friend ostream& operator<<(ostream& os, const Man& m) {
		return os << m.name << " " << m.age << " " << m.pay;
	}
	friend istream& operator>>(istream& os,  Man& m) {
		return os >> m.name >> m.age >> m.pay;
	}
};

