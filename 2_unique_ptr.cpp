#include <iostream>
#include <memory>
template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	~Ptr() { delete obj; }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// 복사와 대입을 할수 없게 하자
	Ptr(const Ptr&) = delete;
	Ptr& operator=(const Ptr&) = delete;
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;

	//Ptr<int> p2 = p1; // 이렇게 사용할수 없게 하자.
						// 이렇게 사용하면 컴파일 에러.!
	// 이런 스마트 포인터가 "unique_ptr" 입니다
	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2 = up1; // error
	std::unique_ptr<int> up3 = std::move(up1); // 이코드는 가능
}


