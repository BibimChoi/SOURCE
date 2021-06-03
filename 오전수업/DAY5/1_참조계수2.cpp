#include <iostream>
#include <vector>
using namespace std;

class Car 
{
	int mColor;

	int refCount = 0; // 자신을 사용하는 포인터가 몇개인지 관리
public:
	void AddRef()  { ++refCount; }
	void Release() { if ( --refCount == 0 ) delete this; }

	// protected 소멸자. 외부에서 직접 delete 하게 되면
	// 소멸자를 호출해야 하는데, 소멸자가 protected이므로 error
protected:
	~Car() { cout << "Car 파괴" << endl; }
};
int main()
{
	Car* p1 = new Car;
	p1->AddRef();			// 규칙 1. 객체 생성시 참조계수 증가

	Car* p2 = p1; 
	p2->AddRef();			// 규칙 2. 객체의 주소를 복사하면 참조계수 증가

//	delete p1; // 이렇게 사용할수 없게 하는 것이 좋다.

	// 규칙 3. 포인터 사용후에는 참조계수 감소
	p2->Release();
	p1->Release();
}






