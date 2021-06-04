#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 클래스를 만들어 봅시다.
// Proxy : 대행자(대신하는 클래스)를 만드는 패턴
// remote proxy : 원격지 서버를 대신하는 클래스

// 장점 1. Client 제작자는 IPC 관련 코드를 사용하지 않아도 서버의 기능을 활용할수 있다.
//     2. 자주 사용되는 명령의 결과는 캐쉬로 관리 할수도 있다.
//		그외.. 여러가지 장점들...

// Proxy : 함수호출(Add())를 명령코드(1)로 변경해서 서버에 전달
// Stub  : 도착한 명령코드(1) 를 다시 함수 호출(server.Add()) 로 변경
//			서버에 있는 dispatch 함수가 stub 입니다.

class Calc
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

	std::cout << pCalc->Add(10, 20) << std::endl;
	std::cout << pCalc->Sub(10, 20) << std::endl;
}







