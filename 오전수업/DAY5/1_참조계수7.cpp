#include <memory>

class Car {};

int main()
{
	// C++ 표준에 shared_ptr 이 있는데.. 왜... 따로 참조계수를 만드나요 ?
	// shared_ptr을 사용하면 안되나요 ??

	// shared_ptr도 결국 참조계수로 관리합니다.
	// 그런데, 객체와는 별도의 메모리 공간을 할당해서 관리합니다.
	std::shared_ptr<Car> sp1(new Car);
	std::shared_ptr<Car> sp2 = sp1;


	// 아래 코드를 생각해 보세요
	Car* p = new Car;
	std::shared_ptr<Car> sp3(p);
	std::shared_ptr<Car> sp4(p);

	// shared_ptr : 관리객체가 객체와는 별도의 메모리 입니다.
	//				관리객체(참조계수)가 2개 만들지는 문제가 있습니다.

	// 하지만 아래 코드 메모리 그림 생각해 보세요
	Truck* p = new Truck;
	AutoPtr<Truck> p1(p);
	AutoPtr<Truck> p2(p);

	// AutoPtr이 안전합니다.
	// 그런데.. AutoPtr은 int등을 사용할수는 없습니다.
	AutoPtr<int> ap = new int; // error.
							// AutoPtr은 RefBase의 파생 클래스
							// 만 관리 가능합니다.

}
