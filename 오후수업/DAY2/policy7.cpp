#include <iostream>
#include <vector>

// STL 컨테이너에 전달하기 위한 메모리 할당 정책을 담은 
// 정책 클래스(STL 자체가 Policy Base Design 으로 설계되었다는 의미 입니다.)

template<typename T> class MyAlloc
{
public:
	// 약속된 함수를 반드시 제공해야 합니다.
	T* allocate(std::size_t sz)
	{
		std::cout << sz << "개의 메모리 할당" << std::endl;
		return new T[sz];
	}
	void deallocate(T* p, std::size_t sz)
	{
		std::cout << sz << "개의 메모리 해지" << std::endl;
		delete[] p;
	}
	// 그리고 추가로 아래 3개가 더 필요 합니다.
	typedef T value_type;
	MyAlloc() = default;
	template<typename U> MyAlloc(const MyAlloc<U>& m) {}
};

int main()
{
	// STL 사용시 메모리 할당기를 변경할수 있습니다.
	std::vector<int, MyAlloc<int> > v;
	
	v.resize(10); // 이순간 메모리 할당은 MyAlloc을 사용하게 됩니다.
}

