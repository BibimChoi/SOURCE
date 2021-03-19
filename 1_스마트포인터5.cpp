#include <iostream>
#include <memory>

void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ? - 아주 중요합니다.
	// 2번, 
	//std::shared_ptr<Point> sp(new Point(1, 2));

	// 자원 + 관리 객체를 "한번에" 메모리 할당해 달라
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
	

	// 아래 코드의 문제점을 생각해 봅시다.
	// 자원 할당후 즉시 shared_ptr에 넘겨야 한다.
	// 아래 처럼 하면 자원 누수의 가능성이 있다.
	foo(std::shared_ptr<int>(new int), goo());

	// make_shared : 자원할당 + shared_ptr 생성이 한번에 이루어집니다. 안전
	foo( std::make_shared<int>(10) , goo());
}


void foo( std::shared_ptr<int> sp, int n) {}



int goo() { return 10; }







