#define USING_GUI
#include "cppmaster.h"

// Client 제작자는 
// 1. 서버제작자에게 2개의 파일을 받아야 합니다. 
//    ICalc.h       : 인터페이스가 담긴 파일
//    CalcProxy.dll : Proxy 객체가 있는 DLL. 
//                    Proxy 의 클래스 이름은 알 필요 없습니다. 
//				      ICalc라는 인터페이스 이름만 알면 됩니다.

// 2. DLL 안에 Proxy를 만드는 "CreateProxy" 함수가 있다는 사실만 알면됩니다

#include "ICalc.h"

int main()
{
	// DLL을 로드해서 약속된 함수를 통해서 Proxy 를 생성합니다.
	void* addr = ec_load_module("CalcProxy.dll"); // linux : dlopen(),  windows : LoadLibrary()

	typedef ICalc*(*F)();

	F f = (F)ec_get_function_address(addr, "CreateProxy"); // 동적모듈에서 함수 주소 찾기
													// linux : dlsym(),   windows : GetProcAddress()
	//--------------------------------------------
	ICalc* pCalc = f();

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

}





