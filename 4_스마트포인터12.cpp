#include <iostream>
#include <thread>
using namespace std::literals;

// CRTP
class Machine : public std::enable_shared_from_this<Machine>
{
	int data;
	std::shared_ptr<Machine> holdMe; // �ڽ��� ���������
									 // �����ϱ� ����
public:
	Machine() { std::cout << "Machine()" << std::endl; }
	~Machine() { std::cout << "~Machine()" << std::endl; }

	void start()
	{
//		holdMe = this; // ?? �ɱ�� ?	
						// this�� raw pointer �̹Ƿ�
						// ������ ������ü ����
//		holdMe = main �������� sp; 

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


