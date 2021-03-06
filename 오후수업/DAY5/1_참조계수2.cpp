#include <iostream>
#include <vector>
using namespace std;

class Car 
{
	int mColor;

	int refCount = 0;
public:
	void AddRef()  { ++refCount; }
	void Release() { if (--refCount == 0) delete this; }

	// protected 소멸자는 외부에서 호출할수 없습니다.
	// 따라서, 외부에서 delete 하는 코드가 있으면 에러 입니다.
protected:
	~Car() { cout << "Car 파괴" << endl; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef();		// 규칙 1. 객체를 만들면 참조 계수 증가

	Car* p2 = p1; 
	p2->AddRef();		// 규칙 2. 객체 주소를 복사하면 참조계수 증가

//	delete p2;

	// 규칙 3. 포인터 사용후에 참조계수 감소
	p2->Release();
	p1->Release(); // 이순간 참조계수가 0이므로 객체 파괴
}








