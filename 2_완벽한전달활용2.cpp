#include <thread>
#include <memory>
#include <iostream>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << " bytes" << std::endl;
	return malloc(sz);
}

class Point
{
	int x, y;
public:
	Point(int a, int b) {  }
};

// std::make_shared 의 원리
template<typename T> 
std::shared_ptr<T> make_shared()
{
	T* p = new T();
}


int main()
{
	// 아래 코드는 동적 메모리 할당이 몇번 발생할까요 ?
	//std::shared_ptr<Point> sp(new Point(1, 2));

	// 아래 코드는 
	// sizeof(Point) + sizeof(관리객체) 를 한번에 메모리 할당하게 됩니다
	std::shared_ptr<Point> sp = std::make_shared<Point>(1, 2);
}







