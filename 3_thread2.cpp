#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	std::thread t1(&foo, 1, 3.4); // 이순간 스레드 생성

	t1.join();	// pthread_join();
//	t1.detach();// 새로운 스레드를 대기하지 않겠다는 것.  

	Test test;
	std::thread t2(&Test::goo, &test, 1, 3.4);
	t2.join();
}





