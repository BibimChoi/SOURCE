#include <iostream>
#include <functional>

template<typename T> 
struct reference_wrapper
{
	T* obj;
public:
	reference_wrapper(T& p) : obj(&p) {}

	// 진짜 참조로 변환될수 있는 변환 연산자
	operator T&() { return *obj; }
};
int main()
{
	int n1 = 10;
	int n2 = 20;

	reference_wrapper<int> r1(n1);
	reference_wrapper<int> r2(n2);

	r1 = r2;

	// 진짜 참조 타입으로 암시적 변환되게 하자.!!
	int& r = r1; // r1.operator int&() 


	std::cout << n1 << std::endl;	
	std::cout << n2 << std::endl;	
	std::cout << r1 << std::endl;	
	std::cout << r2 << std::endl;	
}
