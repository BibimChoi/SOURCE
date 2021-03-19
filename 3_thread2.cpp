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

	Test t;
	std::thread t2(&Test::goo, &t, 1, 3.4);

	t2.join();
	t1.join();  // 종료 대기 - pthread_join()
//	t1.detach();// 주스레드과 관련없이 실행되라..
}


