#include <iostream>

// 1. template 으로 만들어야 한다.
// 2. 얕은 복사 문제를 해결해야 한다.
//    (A) 깊은 복사 - 스마트 포인터에서는 거의 사용안함
//    (B) 참조 계수 - 가장 널리 사용
//    (C) 복사 금지 - 많이 사용
//    (D) move 개념 - 많이 사용

template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = nullptr) : obj(p) {}

	~Ptr() { delete obj; }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;

	Ptr<int> p2 = p1; // 얕은 복사 발생
}


