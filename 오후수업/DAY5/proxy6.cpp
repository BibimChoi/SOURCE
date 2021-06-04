#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"

int main()
{
	void* addr = ec_load_module("CalcProxy.dll"); 
	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");

	//------------------------------------
	ICalc* pCalc = f();  // dll 내부에서 "new Calc" 하고 있습니다.
						 // 사용후에는 delete 해야 합니다.
	pCalc->AddRef(); // 참조계수 증가


	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

	pCalc->Release(); // 참조계수 감소

//	delete pCalc; // 이렇게 하는게 안전할까요 ?
					// 동적모듈(.DLL, .so)이 할당한 자원은
					// 동적모듈에서 해지 하는것이 안전합니다.

}





