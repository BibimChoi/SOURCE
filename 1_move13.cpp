#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
// Rule of 0

// 자원이 필요 하면 자원을 자동관리하는 객체를 사용하자.

// 문자열               ==> char* 대신 string
// p = new int[10]      ==> vector
// 그래도 포인터가 필요 ==> 스마트 포인터

// 자원관리를 직접하지 않게 되면 "디폴트 복사/move"를 사용해도 안전하다.

class People
{
	std::string name;
	int   age;
public:
	People(std::string s, int a) : name(s), age(a)
	{
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




