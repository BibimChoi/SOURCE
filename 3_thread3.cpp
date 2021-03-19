#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;

// 동기화 객체 사용시 "예외"가 발생하면 dead lock 의 가능성이있습니다.
// lock_guard 를 사용하세요

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
	std::lock_guard<mutex> lg(m);

	// 공유 자원 사용	
	shared_data = 200;
}


int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

