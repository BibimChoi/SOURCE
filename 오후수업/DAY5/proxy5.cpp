#define USING_GUI
#include "cppmaster.h"

// 클라이언트 제작자는 서버 제작자에게 2개의 파일을 받으면 됩니다.

// "ICalc.h" : 인터페이스가 담긴 파일.. 이파일이 변경되면 클라이언트를 다시 빌드해야 한다.
//				인터페이스는 최대한 변경되지 않게 설계해야 합니다.

// "CalcProxy.dll" : Proxy가 담긴 DLL
//					새로운 Proxy 를 만들어도 "이름을 동일하게 유지하는 것이 좋습니다."

#include "ICalc.h"

int main()
{
	// 동적모듈(DLL)을 load해서 약속된 함수를 찾아서 호출하면 proxy가 생성됩니다.
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen(),  windows : LoadLibrary()

	typedef ICalc*(*F)();

	F f = (F)ec_get_function_address(addr, "CreateProxy"); // linux : dlsym(), windows : GetProcAddress

	//------------------------------------
	ICalc* pCalc = f(); // Proxy 객체 생성.. 

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

}





