#include <iostream>

// 1. 템플릿으로 만들어야 한다.

template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}

	~Ptr() { delete obj; }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;

	Ptr<int> p2 = p1; // 런타입 에러.!!
						// 얕은 복사!!
}


