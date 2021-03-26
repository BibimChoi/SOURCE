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
	// 핵심 1. () 초기화만 가능하다.
	std::shared_ptr<int> p1(new int);  // ok
//	std::shared_ptr<int> p2 = new int; // error. 생성자가 explict 생성자



	// 핵심 2. 스마트 포인터의 크기
	std::cout << sizeof(p1)   << std::endl; // 8
	std::cout << sizeof(int*) << std::endl; // 4 ( 32bit)



	// 핵심 3. -> 와 . 연산자
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	// 스마트 포인터는 사실 "객체" 입니다.

	// -> : 대상체(Car)의 멤버함수 접근
	sp1->Go();

	// . : shared_ptr 자체의 멤버 함수 사용
	int n = sp1.use_count(); // 2
	Car* p = sp1.get();    // 자원의 raw pointer 얻기
	sp1.reset();  // sp1 = nullptr

}



