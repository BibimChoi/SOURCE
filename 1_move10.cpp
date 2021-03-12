#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>


// 핵심 : move 계열 함수(move 생성자, move대입연산자)
// 함수를 만들때는 반드시 모든 멤버를 move로 옮겨야 합니다.
// 단, primitive type이나 포인터는 move를 사용해도 되고 사용하지 않아도 됩니다.

class People
{
	char* name;
	int   age;
	std::string addr;
public:
	People(const char* s, int a, std::string ad = "seoul") : age(a), addr(ad)
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

	// move 생성자.
	// 
	People(People&& p) 
	  //: name(p.name), age(p.age), addr(p.name) // 절대 이렇게 하지 마세요
											     //  string의 복사 생성자 호출
		: name(p.name), age(p.age), addr(std::move(p.name)) // <<== string move 생성자
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

	People p2 = p1; 
	p2 = p1;		


	
	People p3 = std::move(p1);
	p3 = std::move(p2);			
}




