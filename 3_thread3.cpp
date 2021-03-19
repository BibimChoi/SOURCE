#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;

// 동기화 자원을 직접 사용하면 예외 발생시 dead lock 의 확률이 있다.
/*
void foo()
{
	m.lock();
	// 공유 자원 사용	
	shared_data = 200;

	m.unlock();
}
*/
void foo()
{
	std::lock_guard<std::mutex> lg(m); // 생성자에서 m.lock()
									   // 소멸자에서 m.unlock()
	shared_data = 200;
}



int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

