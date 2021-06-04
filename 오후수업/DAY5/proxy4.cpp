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
// ==> Server 제작자 만들어서 Client 제작자에게 전달하는 것


int main()
{
	// 아래 처럼 Proxy 이름을 바로 사용하면 강한결합입니다.
	// 새로운 버전의 Proxy 가 배포 되면 아래 코드는 수정되야합니다.
	// OCP를 만족하지 못합니다.
	// Calc* pCalc = new Calc;

	// CLient 가 Proxy 사용시 약한결합(인터페이스만 사용)
	// 으로 사용해야 합니다
	ICalc* pCalc = ? ? ? ;

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;

}





