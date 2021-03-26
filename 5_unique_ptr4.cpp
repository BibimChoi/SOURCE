#include <iostream>

template<typename T, typename U, bool b = std::is_empty_v<T>  >
struct PAIR;


// 마지막 인자에 따라 구현을 다르게 하자.
template<typename T, typename U >
struct PAIR<T, U, false>
{
	T first;
	U second;

	PAIR() = default;
	PAIR(const T& a, const U& b) : first(a), second(b) {}

	T& getFirst() { return first; }
	U& getSecond() { return second; }
};

template<typename T, typename U >
struct PAIR<T, U, true> : public T
{
	U second;

	PAIR() = default;
	PAIR(const T& a, const U& b) : T(a), second(b) {}

	T& getFirst() { return *this; }
	U& getSecond() { return second; }
};
//--------------------------------------------


struct Freer
{
	inline void operator()(void* p) const
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};
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
//	T* obj;
//	D  del;
	PAIR<D, T*> mData;
public:
	explicit inline unique_ptr(T* p = 0, const D& d = D()) 
							: mData(d, p) {}

	inline ~unique_ptr()
	{
		//del(obj);
		mData.getFirst()(mData.getSecond());
	}
	inline T* operator->() { return mData.getSecond(); }
	inline T& operator*() { return *mData.getSecond(); }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	// unique_ptr의 삭제자를 변경하는 3가지 형태
	unique_ptr<int, Freer > p1(static_cast<int*>(malloc(100)));

	auto del = [](int* p) { free(p); };
	unique_ptr<int, decltype(del) > p2(static_cast<int*>(malloc(100)), del);

	unique_ptr<int, void(*)(void*) > p3(static_cast<int*>(malloc(100)), free);

	std::cout << sizeof(p1) << std::endl;
	std::cout << sizeof(p2) << std::endl;
	std::cout << sizeof(p3) << std::endl;
}


