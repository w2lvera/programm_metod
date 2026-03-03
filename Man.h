#pragma once

class Man
{
public:
//private:
	char name[50];
	int age;
	int pay;
	//Man student("Vacy", 19, 3300);
	Man(const char*, int, int);
	Man();
	~Man();
	void print(); 
	bool compMan(Man b);
	bool operator >(Man b);
	Man operator = (Man b);
};

