#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 클래스를 만들어 봅시다.
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
