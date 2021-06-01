#include <iostream>
#include <vector>

template<typename T> class MyAlloc
{
public:
	// 사전에 약속된 함수를 반드시 제공해야 합니다.
	T* allocate(std::size_t sz) 
	{
		std::cout << sz << "개 할당" << std::endl;
		return new T[sz]; 
	}
	void deallocate(T* p, std::size_t sz) 
	{
		std::cout << sz << "개 해지" << std::endl;
		delete[] p; 
	}

	// 그리고 아래 3개가 필요 합니다.
	typedef T value_type;
	MyAlloc() = default;
	template<typename U> MyAlloc(const MyAlloc<U>& m) {}
};

int main()
{
	// STL 사용시 메모리 할당기 교체하기
	std::vector<int, MyAlloc<int> > v;

	v.resize(10); //  이순간 사용자가 전달한 MyAlloc<int> 의 약속된 함수
					// 인 allocate()를 사용해서 메모리를 할당하게 됩니다.
}
