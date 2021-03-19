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
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	//std::shared_ptr<Point> sp( new Point(1, 2) );

	// "객체 + 관리객체" 의 크기 메모리를 한번에 붙여서 할당해달라
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);

	// make_shared 장점
	// 1. 메모리 파편화가 줄어든다.
	// 2. 예외 안정성을 보장한다.

	// A. 자원할당후 즉시 자원 관리객체(스마트 포인터)에 전달해야한다
	//    전달하기 전에 다른 작업을 하다가 예외발생시 자원 누수!!

	
//	foo( std::shared_ptr<int>(new int), goo() ); 

	foo( std::make_shared<int>(10) , goo() ); 
}


void foo( std::shared_ptr<int> sp, int n) {}



int goo() { return 10; }




