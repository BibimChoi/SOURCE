#include <iostream>
#include <thread>
using namespace std::literals;

// enable_shared_from_this : this를 사용해서 외부에 있는
//						관리객체를 공유하게 하는 기반 클래스
//						CRTP 기술로 구현
class Machine : public std::enable_shared_from_this<Machine>
{
	int data;
	std::shared_ptr<Machine> holdMe;
public:
	Machine()  { std::cout << "Machine()" << std::endl; }
	~Machine() { std::cout << "~Machine()" << std::endl; }


	void start( )
	{
		holdMe = shared_from_this(); // 외부에 만들어져 있는 관리객체를
									// holdMe가 공유해서 사용하게 한다

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
		sp->start( );
	}
	
	int n;
	std::cin >> n;
}

/*
// 핵심 하나의 raw pointer 는 한개의 스마트포인터 초기화에만
// 사용되어야 한다.
int* p = new int;

std::shared_ptr<int> sp1(p);
std::shared_ptr<int> sp2(p); // 참조계수가 2가 될까요 ?
*/