// 4_상수멤버함수1
#include <iostream>

class Point
{
public:
	int x, y;
	Point(int a, int b)  : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }


	void print()  const  // 상수 멤버 함수
	{
		//x = 10; // error. 상수 멤버 함수에서는 모든 멤버를 상수 취급

		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	const Point p(1, 2);

	p.x = 10;     // error. p는 상수 객체 이므로		
	p.set(10, 20);// error.  	
	p.print();	  // error. 호출되게 하려면 print가 상수 멤버 함수이어야
					// 한다.
		// 핵심 : 상수 객체는 상수 멤버 함수만 호출할수 있다.
}