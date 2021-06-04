#include <iostream>
#include <vector>
using namespace std;

// 참조계수 기능을 제공하는 기반 클래스.
// 참조계수가 필요하면 RefBase로 부터 상속 받으면 됩니다.
class RefBase
{
	int refCount = 0;
public:
	void AddRef() { ++refCount; }
	
	void Release()  // void Release( RefBase* this )
	{
		if (--refCount == 0) 
			delete this; // RefBase 소멸자가 가상함수가 아니면
						// 이 순간 this의 타입이 RefBase* 이므로 RefBase의 소멸자만 호출됩니다.
						// 해결책은 "RefBase"의 소멸자를 가상함수로 해야 합니다.
						// "기반 클래스 소멸자는 가상함수 이어야 한다."
	}

protected:
	virtual ~RefBase() { cout << "RefBase 파괴" << endl; }
};


// Truck 도 참조계수기술로 관리하고 싶습니다.
class Truck : public RefBase
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








