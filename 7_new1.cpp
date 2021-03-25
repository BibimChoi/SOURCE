#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point()				: x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point()						 { LOG_FUNCTION_NAME(); }
};

int main()
{
	// new
	// 1. 메모리 할당
	// 2. 생성자 호출
	// Point* p1 = new Point(1, 2);

	// delete
	// 1. 소멸자 호출
	// 2. 메모리 해지
	// delete p1;

	// 1. 메모리만 할당
	Point* p1 = operator new(sizeof(Point));

	// 4. 메모리만 해지
	operator delete(p1);
}