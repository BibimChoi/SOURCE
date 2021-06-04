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


int main()
{
	Truck* p1 = new Truck;
	p1->AddRef();

	Truck* p2 = p1;
	p2->AddRef();

	p1->Go();

	p2->Release();
	p1->Release();
}








