#include <iostream>
#include <memory>

class Car {};

int main()
{
	// std::shared_ptr<>이 있는데.. 왜.. 또 AutoPtr을 만듭니까 ?
	// 그냥, shared_ptr 사용하면 안되나요 ??

	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;

	
	// 아래 코드의 문제점 생각해 보세요
	Car* p = new Car;
	std::shared_ptr<Car> sp3(p);
	std::shared_ptr<Car> sp4(p);
}
