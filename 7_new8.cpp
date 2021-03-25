#include <vector>
#include <iostream>


template<typename T> struct LogAlloc
{
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "���� �޸� �Ҵ�" << std::endl;
		return static_cast<T*>(malloc(sizeof(T)* sz));
	}
	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "���� �޸� ����" << std::endl;
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
	std::allocator<Point> ax; // Point Ÿ���� �޸� �Ҵ��!
						// ǥ�� �Ҵ��� "operator new()", "operator delete()" ���

	Point* p1 = ax.allocate(1); // Point �Ѱ� �Ҵ�

	ax.construct(p1, 1, 2);		// ������ ȣ��

	ax.destroy(p1);				// �Ҹ��� ȣ��

	ax.deallocate(p1, 1);		// �޸� ����
}