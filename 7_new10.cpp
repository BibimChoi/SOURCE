#define _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING

#include "cppmaster.h"

class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

template<typename T, typename Ax = std::allocator<T> > class vector
{
	T* buff;
	int size;
	int capacity;
	Ax  ax; // �޸� �Ҵ��
public:
	vector(int sz, const T& value = T()) : size(sz), capacity(sz)
	{
		buff = ax.allocate(sz);

		int cnt = 0;
		try
		{
			for (int i = 0; i < sz; i++)
			{
				std::allocator_traits<Ax>::construct(ax, &buff[i], value);
				++cnt;
			}
		}
		catch (...)
		{
			for (int i = 0; i < cnt; i++)
				std::allocator_traits<Ax>::destroy(ax, &buff[i]);

			ax.deallocate(buff, size);

			buff = nullptr;
			size = 0;
			capacity = 0;
		}
	}
	~vector()
	{
		if (buff)
		{
			for (int i = 0; i < size; i++)
				std::allocator_traits<Ax>::destroy(ax, &buff[i]);

			ax.deallocate(buff, size);
			buff = nullptr;
			size = 0;
			capacity = 0;
		}
	}

	void resize(std::size_t newSize, const T& value = T())
	{
		if (newSize > capacity)
		{
			// �޸� �Ҵ� �ʿ�

			// �Ʒ� �ڵ� ������
			// 1. T Ÿ�Կ� ����Ʈ �����ڰ� �ʿ� �ϴ�
			// 2. 
			T* temp = new T[newSize];
		}
		else
		{
			// �޸��Ҵ� �ʿ� ����.
		}

	}
};




int main()
{
	vector<Point> v(10, Point(1, 2));

	v.resize(15, Point(0, 0));
}









// ���� ���� �� : swmooc.lge.com  ���� 4������ ���� �����մϴ�.