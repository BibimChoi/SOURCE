#include <iostream>

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
	T* obj;
	D  del;
public:
	explicit inline unique_ptr(T* p = 0, D d = D()) : obj(p), del(d) {}

	inline ~unique_ptr()
	{
		del(obj);
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

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
}


