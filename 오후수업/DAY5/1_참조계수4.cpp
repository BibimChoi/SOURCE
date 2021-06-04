#include <iostream>
#include <vector>
using namespace std;

// CRTP ( Curiously Recurring Template Pattern )
// 기반 클래스가 템플릿 인데, 파생 클래스 만들때 자신의 이름을 기반클래스의 템플릿 인자로 
// 전달하는 기술

// 기반 클래스 설계시 파생 클래스의 이름을 활용할수 있게 된다.

// 디자인 패턴 : 언어에 무관한 객체지향 설계기술(strategy, composite 등)
// C++ IDioms  : C++ 언어에서만 사용되는 코딩 패턴(CRTP, Policy Base 등)

template<typename T> class RefBase
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }

	void Release()  // void Release( RefBase* this )
	{
		if (--refCount == 0)
//			delete this;  // 이 순간의 this는 RefBase* 입니다.
			delete static_cast<T*>(this);
	}
protected:
	~RefBase() { cout << "RefBase 파괴" << endl; }
};

class Truck : public RefBase< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }
};

int main()
{
	Truck* p = new Truck;
	p->AddRef();
	p->Release();
}








