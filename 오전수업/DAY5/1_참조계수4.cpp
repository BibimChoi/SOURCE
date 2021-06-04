#include <iostream>
#include <vector>
using namespace std;


// CRTP ( Curiously Recurring Template Pattern) 이라는 이름을 가진 기술(C++ 만의 기술)

// 기반 클래스가 템플릿 인데, 파생 클래스가 자신의 이름을 기반클래스 템플릿 인자로 전달하는 것
// 기반 클래스 만들때 파생 클래스의 이름(T)를 사용할수 있게 된다.

template<typename T> 
class RefBase
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()  
	{
		if (--refCount == 0)
			delete static_cast<T*>(this); 
	}
protected:
	~RefBase() { cout << "RefBase 파괴" << endl; }
};

class Truck : public RefBase< Truck >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();
	p1->Release();
}






