#include <iostream>
#include <vector>
using namespace std;

template<typename T> class RefBase
{
	mutable int refCount = 0; 
public:
	void AddRef() const { ++refCount; }

	void Release() const	
	{
		if (--refCount == 0)
			delete static_cast<const T*>(this); 

	}
protected:
	~RefBase() { cout << "RefBase 파괴" << endl; }
};



class Truck : public RefBase< Truck  >
{
public:
	~Truck() { std::cout << "~Truck" << std::endl; }

	void Go() { std::cout << "Go" << std::endl; }
};

// AddRef/Release를 자동으로 호출하는 스마트 포인터를 만들어 봅시다.
template<typename T> 
class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr)       : obj(p)      { if (obj) obj->AddRef();  }
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	// 스마트 포인터의 핵심
	// 객체라도 ->를 사용할수 있게 하기 위한 연산자 재정의
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};

int main()
{
	AutoPtr<Truck> p1 = new Truck; // AutoPtr<Truck> p1(new Truck);
	AutoPtr<Truck> p2 = p1;

	p1->Go();
}





/*
int main()
{
//	Truck* p1 = new Truck;
//	p1->AddRef();

	AutoPtr<Truck> p1 = new Truck; // AutoPtr<Truck> p1(new Truck);

//	Truck* p2 = p1;
//	p2->AddRef();
	AutoPtr<Truck> p2 = p1;


	p1->Go();

//	p2->Release();
//	p1->Release();
}
*/







