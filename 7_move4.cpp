#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Cat() { delete[] name; }

	// 깊은 복사로 구현한 "복사 생성자"
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// 임시객체를 위한 복사 생성자를 
	// 별도로 제공하자.
	// "move 생성자라고 합니다."
	Cat(Cat&& c) : age(c.age), name(c.name)
	{
		c.name = nullptr; // 원본 객체의 자원포인터 reset
						// 이 코드가 되려면 임시객체도
						// 상태를 변경할수 있어야합니다.
						
	}

};

Cat foo()
{
	Cat c("yaong", 5);
	return c;
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;

	Cat c3 = foo(); // 이순간을 생각해 봅시다.
}




