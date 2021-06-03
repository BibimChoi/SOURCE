#include <iostream>
#include <vector>
using namespace std;

// 참조계수 기능을 제공하는 기반 클래스 
class RefBase
{
	int refCount = 0;
public:
	void AddRef()  { ++refCount; }

	void Release()  // void Release(RefBase* this)
	{ 
		if (--refCount == 0) 
			delete this; // 이렇게 delete 하면 RefBase 의 소멸자가 가상이 아닌경우
						// RefBase의 소멸자만 호출
						// 1일차 수업 - "기반 클래스 소멸자는 가상함수 이어야 한다."
	}

protected:
	virtual ~RefBase() { cout << "RefBase 파괴" << endl; }
};

// Truck 도 참조계수 기술로 관리하고 싶다.
class Truck : public RefBase
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






