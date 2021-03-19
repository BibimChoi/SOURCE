#include <iostream>

// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
	// 핵심 1. 
	std::shared_ptr<int> p1(new int);  // ok
//	std::shared_ptr<int> p2 = new int; // error. 생성자가 explicit 입니다.



	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p1)   << std::endl; // 8바이트
	std::cout << sizeof(int*) << std::endl; // 32bit에서 4바이트



	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산자 : 대상체의 멤버 함수
	sp1->Go();

	// . 연산자 : 스마트포인터(shared_ptr)의 멤버 함수
	int n = sp1.use_count(); 

	Car* p = sp1.get(); // 자원의 실제 주소

	sp1.reset(); // sp1 = nullptr 같은 의미. 더이상 사용안함.
}






