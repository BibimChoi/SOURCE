#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Rule Of 5/5 
// 생성자에서 자원 할당하면 C++98 "Rule of 3"
// C++11 => "Rule of 5"
// 소멸자/복사생성자/대입연산자/move생성자/move 대입연산자


class People
{
	char* name;
	int   age;
public:
	People(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~People() { delete[] name; }

	People(const People& p) : age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		age = p.age;

		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		return *this;
	}

	People(People&& p) : name(p.name), age(p.age)
	{
		p.name = nullptr;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		age = p.age;
		delete[] name;		
		name = p.name;
		p.name = nullptr;

		return *this;
	}
};
int main()
{
	People p1("kim", 20);
	People p2 = p1;	// 복사 생성자
	p2 = p1;		// 대입 연산자 

	People p3 = std::move(p1);	// move 생성자
	p3 = std::move(p2);			// move 대입 연산자
}




