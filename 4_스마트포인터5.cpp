#include <iostream>
#include <memory>

/*
void* operator new(size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}
*/
struct Point
{
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 동적 메모리 할당을 몇번하게 될까요 ?
	std::shared_ptr<Point> sp(new Point(1, 2));
	
	
	// 위 처럼 코딩하지 말고 make_shared 를 사용하자.
	// make_shared<타입>(인자) : 타입의 객체를 생성하고
	//							shared_ptr<타입>을 반환

	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);


}

void foo( std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

