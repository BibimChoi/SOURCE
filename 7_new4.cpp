#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T> class vector
{
	T* buff;
	int size;
	int capacity;
public:
	vector(int sz) : size(sz), capacity(sz)
	{
		// 아래처럼 만들면 디폴트 생성자가 있는 타입만 저장할수 있습니다.
		// buff = new T[sz];

		// 1. 메모리만 할당
		buff = static_cast<T*>(operator new(sizeof(T)*sz));


	}
	~vector() {}
};
int main()
{
	vector<Point> v(10);

}