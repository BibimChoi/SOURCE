#include <iostream>

// 삭제자 변경
struct Freer
{
	inline void operator()(void* p) const 
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};
// C++ 표준에 아래 코드는 있습니다.
template<typename T> 
struct default_delete
{
	inline void operator()(T* p) const
	{
		std::cout << "delete" << std::endl;
		delete p;
	}
};

template<typename T, typename D = default_delete<T> > class unique_ptr
{
	T* obj;
public:
	explicit inline unique_ptr(T* p = 0) : obj(p) {}

	inline ~unique_ptr() 
	{
		D d; // 삭제자 객체
		d(obj);
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	// 삭제자 변경
	// 아래처럼 한다면 "삭제자를 별도의 공간에 보관해야 합니다."
	// 생성자에서 전달받은 삭제자를 보관했다가 소멸자에서 사용해야 합니다.
	// unique_ptr<int> p1( static_cast<int*>(malloc(100)), free ) ;

	// 
	unique_ptr<int> p1(new int); // default_delete<int> 사용, 즉, delete 
	unique_ptr<int, Freer> p2(static_cast<int*>(malloc(100))); // 삭제자 변경 
}


