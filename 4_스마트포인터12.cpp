#include <iostream>
#include <thread>
using namespace std::literals;

// CRTP
class Machine : public std::enable_shared_from_this<Machine>
{
	int data;
	std::shared_ptr<Machine> holdMe; // 자신의 참조계수를
									 // 증가하기 위해
public:
	Machine() { std::cout << "Machine()" << std::endl; }
	~Machine() { std::cout << "~Machine()" << std::endl; }

	void start()
	{
//		holdMe = this; // ?? 될까요 ?	
						// this는 raw pointer 이므로
						// 별도의 관리객체 생성
//		holdMe = main 에서만든 sp; 

		holeMe = shared_from_this(); 


		std::thread t(&Machine::work, this);
		t.detach();
	}
	void work()
	{
		std::this_thread::sleep_for(3s);
		data = 10;
		std::cout << "using Machine" << std::endl;

		holdMe.reset();
	}
};
int main()
{
	{
		std::shared_ptr<Machine> sp = std::make_shared<Machine>();
		sp->start();
	}
	int n;
	std::cin >> n;
}


