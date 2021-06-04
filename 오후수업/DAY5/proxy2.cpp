#define USING_GUI
#include "cppmaster.h"

// 디자인패턴의 핵심 1. 공통성과 가변성
//                  2. 복합객체를 만들려면 공통의 부모
//                  3. 중간에 대신하는 것을 만드는 것 : 어답터, proxy, bridge, facade

// 왜 중간 계층을 만들었는가 ?
// adapter : 인터페이스의 변경의 의미!!(list를 스택으로!!)
// proxy   : 인터페이스의 변경이 아닌 대행자를 통한 활용

// 서버를 대신하는 클래스를 만들어 봅시다. ( Proxy Pattern )
// remote proxy : 원격지 서버를 대신하는 클래스

// 장점 1. 사용자가 IPC 를 몰라도 서버를 사용할수 있다.
//      2. 자주 사용되는 연산은 Cache 등으로 관리 할수 있다.
//      3. 그밖에 여러가지로 활용 가능

// Proxy : 함수 호출(Add())을 명령 코드(1)로 변경해서 서버에 전달
// Stub    : 도착한 명령코드(1)을 다시 함수호출(Add())로 변경.

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

	std::cout << pCalc->Add(1, 2) << std::endl;
	std::cout << pCalc->Sub(1, 2) << std::endl;

}
