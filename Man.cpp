#include "Man.h"
#include <iostream>

Man::Man(const char* name, int age, int pay)
{
	
	strcpy_s(this->name, 50, name);
	this->age = age;
	this->pay = pay;
	std::cout << "constructor parametr\n";
}
Man::Man() { 
	name[0] = '\0';
	age = 0;
	pay = 0;
	std::cout << "empty constructor\n";
}
Man::Man(const Man& m) {
	strcpy_s(this->name, m.name);
	this->age = m.age;
	this->pay = m.pay;
}
Man::~Man()
{
	//std::cout << "destructor\n";
}

void Man::setName(const char* name)
{
	strcpy_s(this->name, 50, name);
}

void Man::setAge(int age)
{
	this->age = age;
}

int Man::getAge()
{
	return age;
}


bool Man::compMan(Man b)
{
	return this->pay > b.pay;
}

bool Man::operator>(const Man& b)
{
	return strcmp(this->name, b.name) > 0;
	
}

Man& Man::operator = (const Man& b)
{
	strcpy_s(this->name, b.name);
	this->age = b.age;
	this->pay = b.pay;
	return  *this;
}
