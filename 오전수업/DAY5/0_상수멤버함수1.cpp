// 0_상수멤버함수
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// 상수 멤버 함수 : 컴파일러에게 이 함수에서는 멤버를 변경하지 않을것이라고
	//					약속하는 것
	//					핵심 : 상수 객체는 상수 멤버 함수만 호출 가능하다.
	//						  상수객체일때도 호출가능한 함수를 만들기 위해 필요한 문법
	void print()  const  // 상수 멤버 함수 
	{
//		x = 10;			// error. 상수 멤버 함수 안에서는 모든 멤버는 상수 취급된다.

		cout << x << ", " << y << endl; // ok. 읽기는 가능
	}
};  
int main()
{
	const Point pt(1, 2); // 상수 객체
	pt.x = 10;		// error. public 에 있지만 상수 객체이므로
	pt.set(10, 20); // error.
	pt.print();		// error. 
					// ok - print()가 상수 멤버 함수인 경우
}    
