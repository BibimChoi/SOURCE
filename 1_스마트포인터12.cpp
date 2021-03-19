#include <iostream>
#include <thread>
using namespace std::literals;

// std::enable_shared_from_this : this를 가지고
//	 외부에서 만든 관리 객체에 접근하게 하는 기술
class Machine : std::enable_shared_from_this<Machine>
{
	int data;
	std::shared_ptr<Machine> holdMe;
public:
	Machine()  { std::cout << "Machine()" << std::endl; }
	~Machine() { std::cout << "~Machine()" << std::endl; }

	void start()
	{
		holdMe = shared_from_this();
				// ok.. main 에서 만든 sp의 관리객체를 공유하게 된다.

		std::thread t(&Machine::work, this);
		t.detach();
	}
	void work()
	{
		std::this_thread::sleep_for(3s);
		data = 10;
		std::cout << "using Machine" << std::endl;
		holdMe.reset(); // 자원 포기. 즉, 이순간, Machine 파괴.
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






/*
int* p = new int;

std::shared_ptr<int> sp1(p);
//std::shared_ptr<int> sp2(sp1); // 참조계수 2

std::shared_ptr<int> sp2(p);  // 참조계수가 2가아니라
							// 새로운 관리 객체 생성
							*/