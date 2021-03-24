#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// move 생성자 안에서 "모든 객체형 멤버"는 반드시 "move로 옮겨야 한다."

class People
{
	char* name;
	int   age;
	std::string addr;
public:
	People(const char* s, int a, std::string addr = "unknown") : age(a), addr(addr)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}



	~People() { delete[] name; }

	People(const People& p) : age(p.age), addr(p.addr)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		std::cout << "복사생성자" << std::endl;
	}
	   
	People& operator=(const People& p)
	{
		if (&p == this) return *this;

		std::cout << "복사 대입연산자" << std::endl;
		age = p.age;

		addr = p.addr;


		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);

		return *this;
	}

	People(People&& p) 
//		: age(p.age), name(p.name), addr(p.addr) // 절대이렇게 하지 마세요. string의 복사 생성자호출
		: age(p.age), name(p.name), addr(std::move(p.addr))  //<<<=== 이렇게 해야 합니다.
	{
		p.name = nullptr;
		std::cout << "move 생성자" << std::endl;
	}

	People& operator=(People&& p)
	{
		if (&p == this) return *this;

		std::cout << "move 대입연산자" << std::endl;
		age = p.age;
		addr = std::move(addr);

		delete[] name;
		name = p.name;
		p.name = nullptr;

		return *this;
	}
};
int main()
{
	People p1("kim", 20);

	People p2 = p1; // 복사 생성자
	p2 = p1;		// 대입 연산자

	People p3 = std::move(p1);
	p3 = std::move(p2);
}




