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
	D  del;
public:
	explicit inline unique_ptr(T* p = 0, D d = D() ) : obj(p), del(d)  {}

	inline ~unique_ptr()
	{
//		D d;		// error. 람다표현식은 디폴트 생성될수 없다.
		del(obj);
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	// 삭제자로 람다 표현식 사용
	//unique_ptr<int, [](int* p) { free(p); }  > p2(static_cast<int*>(malloc(100)));
								// 람다표현식의 결과는 타입이 아닌 객체

	//unique_ptr<int, decltype([](int* p) { free(p); }) > p2(static_cast<int*>(malloc(100)));
							// error. 람다표현식은 평가되지 않은 표현식에 넣을수 없다.
	
	auto del = [](int* p) { free(p); };

	unique_ptr<int, decltype(del) > p2(static_cast<int*>(malloc(100)), del );

	// 진짜 함수도 사용가능
	unique_ptr<int, void(*)(void*) > p3(static_cast<int*>(malloc(100)), free );
}


