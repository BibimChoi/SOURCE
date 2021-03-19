#include <iostream>
#include <thread>
using namespace std::literals;

// std::enable_shared_from_this : this�� ������
//	 �ܺο��� ���� ���� ��ü�� �����ϰ� �ϴ� ���
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
				// ok.. main ���� ���� sp�� ������ü�� �����ϰ� �ȴ�.

		std::thread t(&Machine::work, this);
		t.detach();
	}
	void work()
	{
		std::this_thread::sleep_for(3s);
		data = 10;
		std::cout << "using Machine" << std::endl;
		holdMe.reset(); // �ڿ� ����. ��, �̼���, Machine �ı�.
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
//std::shared_ptr<int> sp2(sp1); // ������� 2

std::shared_ptr<int> sp2(p);  // ��������� 2���ƴ϶�
							// ���ο� ���� ��ü ����
							*/