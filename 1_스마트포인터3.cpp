#include <iostream>

// 참조계수 개념을 가진 스마트 포인터
template<typename T> class Ptr
{
	T* obj;
	int* ref; 
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int(1); // 1로 초기화!
	}
	// 참조계수를 사용하는 복사 생성자 모양
	Ptr(const Ptr& p)
		: obj(p.obj), ref(p.ref)
	{
		++(*ref); // 참조계수를 증가.
	}
	~Ptr()
	{
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;

	Ptr<int> p2 = p1; // 문제점!!!!
}



