#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
//	Point() : x(0), y(0) { LOG_FUNCTION_NAME(); }
	Point(int a, int b) : x(a), y(b) { LOG_FUNCTION_NAME(); }
	~Point() { LOG_FUNCTION_NAME(); }
};

int main()
{
	// 힙에 Point 한개를 만들어 보세요
	Point* p1 = new Point(0, 0);

	// 힙에 Point 10개를 만들어 보세요

}
