

// github.com/codenuri/SOURCE 에서 "DAY5" 사전소스 받으시면 됩니다.


// VS 사용하시는 분은


// "x86","Debug" 로 설정하세요


// Windows SDK 버전 설정해 주세요












#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Rule Of 3/5 - 102page

// 생성자에서 자원을 할당하게 되면
// 3개의 함수(소멸자, 복사 생성자, 대입연산자)가
// 필요하다. ====>  Rule Of 3
// 대입연산자의 구현 방법은 "C++기본서적"을 참고 해보세요.

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
	~People() { delete[] name;  }

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
};
int main()
{
	People p1("kim", 20);
	People p2 = p1; 
	p2 = p1; 
}




