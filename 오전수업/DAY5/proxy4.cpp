#define USING_GUI
#include "cppmaster.h"

// 핵심 : 약한 결합

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

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

// 위에 있는 Proxy 클래스는 누가 만들까요 ?
// ==> Server 제작자 가 만들어서 클라이언트 제작자에게 배포

int main()
{
	// 아래처럼 Proxy를 사용하면 강한 결합 입니다.
	// Proxy 클래스가 새롭게 배포되면
	// 아래 코드는 수정되어야 합니다.
	// OCP를 만족하지 못합니다
	// Calc* pCalc = new Calc;

	// Client는 Proxy를 사용시 약한결합을 해야 합니다.
	ICalc* pCalc = new Calc;

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

}





