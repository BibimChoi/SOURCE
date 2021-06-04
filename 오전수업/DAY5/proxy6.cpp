#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

int main()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy"); 												
	//--------------------------------------------
	ICalc* pCalc = f(); // new Calc 하므로.. 언젠가는 delete 되야 합니다.

	pCalc->AddRef(); // 이 코드가 되려면 ICalc 인터페이스에 AddRef가 있어야 합니다.


	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

//	delete pCalc; // 이 코드가 안전할까요 ?
				// 동적 모듈이 할당한 자원은
				// 동적 모듈에서 해지하는 것이 안전합니다.

	pCalc->Release();
}





