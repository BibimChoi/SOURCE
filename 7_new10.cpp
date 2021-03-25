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
	Ax  ax; // 메모리 할당기
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
			// 메모리 할당 필요

			// 아래 코드 문제점
			// 1. T 타입에 디폴트 생성자가 필요 하다
			// 2. 
			T* temp = new T[newSize];
		}
		else
		{
			// 메모리할당 필요 없다.
		}

	}
};




int main()
{
	vector<Point> v(10, Point(1, 2));

	v.resize(15, Point(0, 0));
}









// 내일 최종 평가 : swmooc.lge.com  에서 4시정도 부터 진행합니다.