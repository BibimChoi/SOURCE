#include <iostream>

// ������ ����
struct Freer
{
	inline void operator()(void* p) const
	{
		std::cout << "free" << std::endl;
		free(p);
	}
};
// C++ ǥ�ؿ� �Ʒ� �ڵ�� �ֽ��ϴ�.
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
//		D d;		// error. ����ǥ������ ����Ʈ �����ɼ� ����.
		del(obj);
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	// �����ڷ� ���� ǥ���� ���
	//unique_ptr<int, [](int* p) { free(p); }  > p2(static_cast<int*>(malloc(100)));
								// ����ǥ������ ����� Ÿ���� �ƴ� ��ü

	//unique_ptr<int, decltype([](int* p) { free(p); }) > p2(static_cast<int*>(malloc(100)));
							// error. ����ǥ������ �򰡵��� ���� ǥ���Ŀ� ������ ����.
	
	auto del = [](int* p) { free(p); };

	unique_ptr<int, decltype(del) > p2(static_cast<int*>(malloc(100)), del );

	// ��¥ �Լ��� ��밡��
	unique_ptr<int, void(*)(void*) > p3(static_cast<int*>(malloc(100)), free );
}


