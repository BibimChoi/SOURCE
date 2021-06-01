
// 1. codexpert.org  에서 DAY3.zip 받으세요 ( ID : 이메일, PASS : 123456 )

// 2. 압축 풀고 Visual Studio 에서 열어 주세요

// 3. "Debug", "X86"

// 4. Windows SDK 버전과 플랫폼 도구집합 버전 설정해 주세요 
//    ( 프로젝트 메뉴 - DAY3 속성 메뉴)














#include <iostream>
// 핵심 1. 멤버 함수는 호출시 this가 같이 전달됩니다. - this call 방식이라고 합니다.
//      2. static 멤버함수는 this가 추가되지 않습니다.
class Point
{
	int x, y;
public:
	void set(int a, int b)  // void set(Point* this, int a, int b)
	{						
		x = a;				// 	this->x = a
		y = b;				//  this->y = b
	}		
	static void foo(int a)	// void foo(int a)
	{
		x = a;				// this->x = a;  처럼 변경되야 하는데 this가 없습니다.
	}						//		그래서 error. 
};
int main()
{
	Point::foo(10); // static 멤버 함수는 객체가 없어도 호출가능합니다
					// push 10
					// call Point::foo

	Point p1, p2;

	p1.set(10, 20); // 이 한줄의 정확한 원리를 생각해 봅시다.
					// set(&p1, 10, 20) 으로 변경됩니다.
					// push		20
					// push		10			// 실제 인자는 스택으로 넣고(32bit)
					// mov		ecx, &p1	// 객체 주소는 ecx 레지스터에 담은후
					// call		Point::set	// 함수호출
}





