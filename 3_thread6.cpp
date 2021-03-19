#include <iostream>
#include <thread>
#include <atomic>
// atomic

//int x = 0;
std::atomic<int> x = 0; // + 연산등이 스레드에 안전하게 동작한다.

void foo()
{
	x = x + 1;
}

int main()
{
	std::thread t(&foo);
	t.join();
}
