#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 스레드간 통신
// promise & future

// 1. promise의 참조를 받아라!!
void foo( std::promise<int>& pm )
{
	std::this_thread::sleep_for(5s);

	pm.set_value(100); // 주 스레드에 전달
}

int main()
{
	// 스레드 생성시, promise 객체를 만들어서 ref(pm)로 전달
	std::promise<int> pm;

	std::thread t(&foo, std::ref(pm) ); // ref(pm) : pm을 참조로 전달해달라는 것

	// 미래에  결과를 담을 future 객체 생성
	std::future<int> fut = pm.get_future(); // 블럭킹 안됨.

	int ret = fut.get();  // 이순간, 값이 들어 올때 까지 blocking 됩니다.

	t.join();
}


