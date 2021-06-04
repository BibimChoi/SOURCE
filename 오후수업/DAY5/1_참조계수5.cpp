#include <iostream>
#include <vector>
using namespace std;

template<typename T> class RefBase
{
	mutable int refCount = 0; // mutable 멤버 데이타
							  // 상수 멤버 함수에서도 값을 변경할수 있게 하는 멤버 데이타
public:
	
	// 참조계수 관련 멤버 함수는 "상수 멤버 함수" 가 되어야 합니다.
	void AddRef() const { ++refCount; }

//	void Release()			// void Release( RefBase* this )
	void Release() const	// void Release( const RefBase* this )
	{
		if (--refCount == 0)
//			delete static_cast<T*>(this); // error
										  // const RefBase* => Truck* 로 캐스팅하는 코드인데..
										  // static_cast 는 상수 성을 제거할수 없으므로 error

			delete static_cast<const T*>(this); // ok
												// const RefBase* => const Truck* 로 캐스팅하는 코드
												// const 를 제거하는 것이 아니므로 
												// static_cast 해도 된다.
								
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
	const Truck* p = new Truck;

	// 아래 코드가 되야 할까요 ? 안되야 할까요 ?
	// 상수 객체라도 수명관리는 가능해야 합니다.
	p->AddRef();   // 호출되어야 합니다.
	p->Release();  // 상수 멤버함수로 해야 합니다.
}








