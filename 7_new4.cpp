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
	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
	{
		// �Ʒ�ó�� ����� ����Ʈ �����ڰ� �ִ� Ÿ�Ը� �����Ҽ� �ֽ��ϴ�.
		// buff = new T[sz];

		// 1. �޸𸮸� �Ҵ�
		buff = static_cast<T*>(operator new(sizeof(T)*sz));

		// 2. ������ ȣ��
		for (int i = 0; i < sz; i++)
		{
			// new(&buff[i]) T; // ����Ʈ ������ ȣ��
			new(&buff[i]) T(value); // ok.. ���� ������ ���
		}

	}
	~vector() {}
};
int main()
{
//	Point pt(1, 2);
//	vector<Point> v(10, pt);
	vector<Point> v(10, Point(1,2) );

}