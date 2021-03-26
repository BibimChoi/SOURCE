#include <iostream>
#include <thread>
using namespace std::literals;

class Machine 
{
	int data;
public:
	Machine()  { std::cout << "Machine()" << std::endl; }
	~Machine() { std::cout << "~Machine()" << std::endl; }

	void start()
	{
	
		std::thread t(&Machine::work, this);
		t.detach();
	}
	void work()
	{
		std::this_thread::sleep_for(3s);
		data = 10;
		std::cout << "using Machine" << std::endl;
	}
};
int main()
{	
	std::shared_ptr<Machine> sp = std::make_shared<Machine>();
	sp->start();

	int n;
	std::cin >> n;
}


