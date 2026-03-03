#pragma once
#include <fstream>
using namespace std;
class MyString
{
private:
	char* str;
	int n;
public:
	MyString();
	MyString(int n);
	MyString(const char* s);
	MyString(const MyString& s);
	MyString& operator=(const MyString& s);
	char& operator[](int c);
	~MyString();
	friend ostream& operator<<(ostream& os
		, MyString& s) {
		return os << s.str;
	}
};

