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
		// �Ʒ�ó�� ����� ����Ʈ �����ڰ� �ִ� Ÿ�Ը� �����Ҽ� �ֽ��ϴ�.
		// buff = new T[sz];

		// 1. �޸𸮸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*sz));


	}
	~vector() {}
};
int main()
{
	vector<Point> v(10);

}