#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) { if (obj) obj->AddRef(); }
	AutoPtr(const AutoPtr<T>& ap) : obj(ap.obj) { if (obj) obj->AddRef(); }
	~AutoPtr() { if (obj) obj->Release(); }

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};


int main()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	//--------------------------------------------
	AutoPtr<ICalc> pCalc = f(); 

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}





