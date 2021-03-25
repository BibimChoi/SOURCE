#include <vector>
#include <iostream>


template<typename T> struct LogAlloc
{
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "개의 메모리 할당" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)* sz));
	}
	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "개의 메모리 해지" << std::endl;
		free(p);
	}
	void destroy(T* p) { p->~T(); }

	template<typename ... Ts>
	void construct(T* p, Ts&& ... args)
	{
		new(p) T(std::forward<Ts>(args)...);
	}

	using value_type = T;
	LogAlloc() = default;
	template<typename U> LogAlloc(const LogAlloc<U>&) {}
};

int main()
{
	std::allocator<Point> ax; // Point 타입의 메모리 할당기!
						// 표준 할당기는 "operator new()", "operator delete()" 사용

	Point* p1 = ax.allocate(1); // Point 한개 할당

	ax.construct(p1, 1, 2);		// 생성자 호출

	ax.destroy(p1);				// 소멸자 호출

	ax.deallocate(p1, 1);		// 메모리 해지
}