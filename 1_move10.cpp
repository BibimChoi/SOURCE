#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
// 이소스에서의 핵심
// move 계열 함수에서는 모든 멤버를 move로 옮겨라!!!


class People
{
	char* name;
	int   age;
	std::string addr;
public:
	People(const char* s, int a, std::string ad= "seoul") 
			: age(a), addr(ad)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~People() { delete[] name; }

	People(const People& p) : age(p.age), addr(p.addr)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		age = p.age;
		addr = p.addr;

		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		return *this;
	}
	// 핵심 : move 계열 함수 에서는 모든 멤버를 move 로 옮겨라!!!
	People(People&& p) 
//		: name(p.name), age(p.age), addr(p.addr) // string 복사 생성자 호출.. 잘못!!!
		: name(p.name), age(p.age), addr(std::move(p.addr)) // ok
	{
		p.name = nullptr;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		age = p.age;
		addr = std::move(p.addr);

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




