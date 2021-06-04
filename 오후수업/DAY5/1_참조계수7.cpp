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
	// shared_ptr은 객체와 관리객체(참조계수)가 별도의 메모리 공간입니다.
	// 아래 코드는 관리객체가 2개 생성됩니다.
	Car* p = new Car;
	std::shared_ptr<Car> sp3(p);
	std::shared_ptr<Car> sp4(p);

	// 이제 아래 코드를 보세요
	// 핵심 : 참조계수가 객체안에 있습니다.
	Truck* p = new Truck;
	AutoPtr<Truck> p1(p);
	AutoPtr<Truck> p2(p);

	// 그런데.. 아래 코드는 될까요 ?
	AutoPtr<int> p3 = new int; // error.
								// int 에는 AddRef가 없습니다.

	// 결론
	// AutoPtr : RefBase로 부터 파생된 타입만 가능
	// shared_ptr : 모든 타입 사용가능
}
