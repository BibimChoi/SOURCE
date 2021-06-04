#define USING_GUI
#include "cppmaster.h"

// RPC( Remote Procedure Call ) : 다른 프로세스의 함수를 호출하는 것
// java 는 RMI( Remote Method Invocation ) 이라고 합니다.

// 서버와 Proxy 가 동일한 함수를 제공함을 인터페이스로 약속한다.
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// 서버의 함수와 이름이 동일함을 약속한다.(인터페이스 구현)
class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* pCalc = new Calc;

	std::cout << pCalc->Add(1, 2) << std::endl;
	std::cout << pCalc->Sub(1, 2) << std::endl;

}
