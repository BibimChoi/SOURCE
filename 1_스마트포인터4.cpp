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
//	std::shared_ptr<int> p2 = new int; // error. 생성자가 explicit 


	// 핵심 2. 스마트 포인터의 크기 - 대부분의 환경에서 
	//								raw pointer의 2배
	std::cout << sizeof(p1)   << std::endl; // 8 byte
	std::cout << sizeof(int*) << std::endl; // 32비트 환경 4byte


	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// -> 연산자 : 대상체(Car) 의 멤버에 접근.
	sp1->Go();

	// . 연산자 : shared_ptr 자체의 멤버 함수
	int n = sp1.use_count(); // 참조계수 얻기 - 2
	Car* cp = sp1.get(); // 자원의 실제 포인터 얻기
	sp1.reset();   // 자원 포기!! - 
}



