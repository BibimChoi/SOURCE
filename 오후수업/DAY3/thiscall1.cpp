
// 1. codexpert.org  에서 DAY3.zip 받으세요 ( ID : 이메일, PASS : 123456 )

// 2. 압축 풀고 Visual Studio 에서 열어 주세요

// 3. "Debug", "X86"

// 4. Windows SDK 버전과 플랫폼 도구집합 버전 설정해 주세요 
//    ( 프로젝트 메뉴 - DAY3 속성 메뉴)

// Ctrl + F5 빌드로 문제 없으면 됩니다.












#include <iostream>
// 핵심 1. 멤버 함수 호출시 객체의 주소(this)가 같이 전달됩니다 - this call 
//      2. static 멤버함수는 this가 전달되지 않는다.
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set( Point* this, int a, int b)
	{						
		x = a;				// 	this->x = a;
		y = b;				//  this->y = b; // 이렇게 변경되게 됩니다.
	}						

	static void foo(int a)	// void foo(int a)
	{
		x = a;				// this->x = a		처럼 변경되어야 하는데..
	}						//		this가 없으므로 컴파일 에러
							// 그래서 static 멤버함수는 멤버 데이타 접근안됨
};
int main()
{
	Point::foo(10); // static 멤버 함수는 객체없이 호출가능!
					// push		10
					// call		Point::foo


	Point p1, p2;

	p1.set(10, 20); // 이 한줄의 정확한 원리를 생각해 봅시다.
				    // set(&p1, 10, 20) 으로 처럼 호출됩니다.
					// push		20
					// push		10       => 진짜 인자는 스택으로(32bit)
					// mov		ecx, &p1 => 객체 주소를 ecx 레지스터에
					// call		Point::set  
}



