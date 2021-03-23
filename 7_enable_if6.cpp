// 7_enable_if6
#include <iostream>
#include <type_traits>

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1(2.1, 3.4);
}