#include <iostream>

class Point { int x, y; };

void foo(const Point& pt) {}

int main()
{
	Point pt;
	foo(pt);
	foo(Point());

}