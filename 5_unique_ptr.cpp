#include <iostream>

// 복사와 대입을 금지하는 스마트 포인터
template<typename T> class unique_ptr
{
	T* obj;
public:
	explicit inline unique_ptr(T* p = 0) : obj(p) {}

	inline ~unique_ptr() { delete obj; }

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	// 복사생성자와 대입연산자 삭제
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	unique_ptr<int> p1(new int);
	*p1 = 10;
	std::cout << *p1 << std::endl;

//	unique_ptr<int> p2 = p1;	// error					
}


