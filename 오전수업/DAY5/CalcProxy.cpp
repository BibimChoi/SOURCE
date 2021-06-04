// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

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

// 이 DLL 사용자는 DLL 안에 있는 Proxy 의 클래스 이름을
// 알지 못하고, 알아도 사용하면 안됩니다.(약한결합을 위해서)
// DLL 안의 약속된 함수를 만들어서 Proxy 객체를 생성합니다.
extern "C" __declspec(dllexport)
ICalc* CreateProxy()
{
	return new Calc;
}

// DLL 로 빌드하는 방법

// Visual Studio 컴파일러이름은 "cl.exe" 입니다.

// 시작메뉴 - Visual Studio2017 폴더 - 개발자 명령프롬프트 실행후, 소스가 있는 폴더에 이동
// 아래 명령으로 빌드

// cl CalcProxy.cpp  /LD  /link  user32.lib  gdi32.lib   kernel32.lib 
