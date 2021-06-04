#include <iostream>
#include <vector>
using namespace std;

class Car {};

vector<Car*> v;

void foo()
{
	// 객체를 만드는 것은 어렵지 않습니다.
	// 하지만, 객체를 delete 하는 것은 쉽지 않습니다.
	// (여러곳에서 사용하고 있을수 있으므로!!)
	Car* p = new Car;

	v.push_back(p);

	// 여기서는 더이상 p가 필요없습니다.
	delete p; // 이렇게 해도 될까요 ?
}

int main()
{
	foo();
}

