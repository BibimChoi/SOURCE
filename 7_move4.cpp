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

	// 깊은 복사로 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
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




