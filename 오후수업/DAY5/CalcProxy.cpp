#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// CalcProxy.cpp
class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b)
	{
		return ec_send_server(server, 1, a, b);
	}
	int Sub(int a, int b)
	{
		return ec_send_server(server, 2, a, b);
	}
};

// 클라이언트 제작자는 이 Proxy DLL안에 있는 클래스 이름을
// 알수 없습니다. 알아도 사용하면 안됩니다.(강한 결합이므로)

// Calc Proxy 객체를 만드는 약속된 함수를 제공합니다.
extern "C" __declspec(dllexport)
ICalc* CreateProxy()
{
	return new Calc;
}

// 빌드 하는 법
// VS의 컴파일러는 "cl.exe" 입니다.

// 시작 버튼 => Visual Studio 2017 폴더 => 개발자 명령 프롬프트 실행후

// 소스가 있는 폴더에 와서

// cl CalcProxy.cpp /LD  /link  user32.lib  gdi32.lib   kernel32.lib



