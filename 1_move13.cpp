#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// Rule of 0
// ==> 자원관리가 필요하다면 직접 관리 하지 말고, 자동으로 관리되는 타입을 사용해라
// 문자열 => string
// 진짜포인터필요 => 스마트 포인터
// p =new int[10] => vector !!!

// 그러면 복사 계열과 move 계열을 모두 자동 지원 받는다.
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
	People p2 = p1;	// 복사 생성자
	p2 = p1;		// 대입 연산자 

	People p3 = std::move(p1);	// move 생성자
	p3 = std::move(p2);			// move 대입 연산자
}




