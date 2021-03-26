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
public:
	explicit inline unique_ptr(T* p = 0) : obj(p) {}

	inline ~unique_ptr() 
	{
		D d; // ������ ��ü
		d(obj);
	}

	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }

	unique_ptr(const unique_ptr&) = delete;
	unique_ptr& operator=(const unique_ptr&) = delete;
};
int main()
{
	// ������ ����
	// �Ʒ�ó�� �Ѵٸ� "�����ڸ� ������ ������ �����ؾ� �մϴ�."
	// �����ڿ��� ���޹��� �����ڸ� �����ߴٰ� �Ҹ��ڿ��� ����ؾ� �մϴ�.
	// unique_ptr<int> p1( static_cast<int*>(malloc(100)), free ) ;

	// 
	unique_ptr<int> p1(new int); // default_delete<int> ���, ��, delete 
	unique_ptr<int, Freer> p2(static_cast<int*>(malloc(100))); // ������ ���� 
}


