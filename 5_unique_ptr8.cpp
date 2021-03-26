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


template<typename T> struct default_delete
{
	inline void operator()(T* p) const
	{
		std::cout << "delete" << std::endl;
		delete p;
	}
};
template<typename T> struct default_delete<T[]>
{
	inline void operator()(T* p) const
	{
		std::cout << "delete[]" << std::endl;
		delete[] p;
	}
};


template<typename T, typename D = default_delete<T> > class unique_ptr
{
	PAIR<D, T*> mData; // PAIR(D, int[]*> mData;

public:
	explicit inline unique_ptr(T* p = 0, const D& d = D())
		: mData(d, p) {}

	inline ~unique_ptr()
	{
		mData.getFirst()(mData.getSecond());
	}
	inline T* operator->() { return mData.getSecond(); }
	inline T& operator*() { return *mData.getSecond(); }
	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	unique_ptr(unique_ptr&& up) noexcept : mData(std::move(up.mData))
	{
		up.mData.getSecond() = nullptr;
	}

	unique_ptr& operator=(unique_ptr&& up) noexcept
	{
		mData = std::move(up.mData);
		up.mData.getSecond() = nullptr;
		return *this;
	}
};


// 부분 특수화는 디폴트 값을 표기 하지 않습니다.
template<typename T, typename D> class unique_ptr< T[], D>
{
	PAIR<D, T*> mData;

public:
	explicit inline unique_ptr(T* p = 0, const D& d = D())
		: mData(d, p) {}

	inline ~unique_ptr()
	{
		mData.getFirst()(mData.getSecond());
	}
	inline T* operator->() { return mData.getSecond(); }

	// 배열 버전은 * 연산은 지원하지 말고 [] 연산을 지원 한다.
	//inline T& operator*() { return *mData.getSecond(); }

	inline T& operator[](int idx) { return mData.getSecond()[idx]; }



	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;

	unique_ptr(unique_ptr&& up) noexcept : mData(std::move(up.mData))
	{
		up.mData.getSecond() = nullptr;
	}

	unique_ptr& operator=(unique_ptr&& up) noexcept
	{
		mData = std::move(up.mData);
		up.mData.getSecond() = nullptr;
		return *this;
	}
};
// 자원의 할당과 unique_ptr의 생성이 한번에 되어야 안전합니다.
template<typename T, typename ... Ts>
unique_ptr<T> make_unique(Ts&& ... args)
{
	return unique_ptr<T>(new T(std::forward<Ts>(args)...));
}

int main()
{
	unique_ptr<int>   up1( new int );

	unique_ptr<int>   up2 = make_unique<int>(5);
	
}













