#include <iostream>
#include <vector>
using namespace std;


template<typename T>
class RefBase
{
	mutable int refCount = 0; // mutable 멤버 데이타 : 상수멤버 함수에서도
							  //					   멤버의 값을 변경할수 있다.
public:
	// 참조계수 관련 멤버 함수는 "상수멤버함수"가 되어야 합니다.
	// 상수객체라도 객체의 수명은 관리할수 있어야 합니다.
	void AddRef() const { ++refCount; }

//	void Release()		  // void Release( RefBase* this)
	void Release() const  // void Release( const RefBase* this)
	{
		if (--refCount == 0)
//			delete static_cast<T*>(this); // 왜 에러일까요 ?
										  // const RefBase* ==> Truck* 로 변경인데.		
										  // static_cast 는 const 속성을 제거할수 없다.

			delete static_cast<const T*>(this); // ok
												// const RefBase* => const Truck* 이므로
											   // const를 제거하는 캐스팅은 아님.
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
	const Truck* p1 = new Truck;

	// 상수객체라도.. 객체의 수명은 관리 할수 있어야 한다.
	// 참조계수 관련 함수는 "상수 멤버 함수"가 되어야 한다.
	p1->AddRef();
	p1->Release();
}






