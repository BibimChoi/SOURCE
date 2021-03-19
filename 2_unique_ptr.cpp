#include <iostream>

template<typename T> class Ptr
{
	T* obj;
public:
	Ptr(T* p = nullptr) : obj(p) {}

	~Ptr() { delete obj; }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	// 복사와 대입을 금지하자.
	Ptr(const Ptr&) = delete;
	Ptr& operator=(const Ptr&) = delete;
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	std::cout << *p1 << std::endl;

//	Ptr<int> p2 = p1; // 컴파일 에러.!!


	std::unique_ptr<int> up1(new int);
	std::unique_ptr<int> up2 = up1;            // error. 자원을 공유할수 없다.
	std::unique_ptr<int> up3 = std::move(up1); // ok.. 자원의 이동은 가능
}






