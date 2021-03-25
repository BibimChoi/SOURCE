#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

int main()
{
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	// make_shared 의 대표적인 2가지 장점
	// 1. 메모리의 효율성( 객체 + 관리객체를 한번에 할당)
	// 2. 예외 안정성

	foo(std::shared_ptr<Point>(new Point(1, 2)), goo());
}

void foo(std::shared_ptr<Poit> sp, int a ) {}

int goo() { return 0; }








