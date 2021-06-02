// 멤버변수포인터
#include <iostream>

struct Point
{
	int x;
	int y;
};

int main()
{
	int n = 0;
	int* p1 = &n;	// int타입 변수의 주소

	int Point::*p2 = &Point::y; // 멤버 변수(함수가아님)의 주소
							// 주의!!! 지금 Point 객체는 없습니다
							// C(linux 커널)언어에서 유명한 offsetof() 와 같은 기능
	std::cout << p2 << std::endl; // 1

	printf("%d\n", p2); // 4.. - 이게 맞습니다. 위코드는 cout의 버그..

//	*p2 = 10; // bug.... 객체가 없습니다. p2는 offset일뿐입니다.
				// 빌드도 안됩니다.

	Point pt;

	pt.*p2 = 100; // ok.. pt.y = 100 입니다.

	std::cout << pt.y << std::endl; // 100
}







