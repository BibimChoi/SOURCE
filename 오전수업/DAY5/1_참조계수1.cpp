#include <iostream>
#include <vector>
using namespace std;

class Car {};

vector<Car*> v;

void foo()
{
	// 객체는 만드는 것은 쉽다...
	// 하지만 객체를 파괴(delete)하는 것은 어렵다.
	// => 그래서, 참조계수(reference counting) 이라는 기술로 객체의 수명을 관리하는
	//	  경우가 많다.
	Car* p = new Car;

	v.push_back(p);


	// 여기서는 더이상 p가 필요없습니다.
	delete p; // 이렇게 해도 될까요 ?
}

int main()
{
	foo();
}

