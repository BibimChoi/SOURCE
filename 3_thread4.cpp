#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 스레드간 통신
// promise & future

// 1. 스레드 함수에서 인자로 Promise의 참조 받아라
void foo( std::promise<int>& pm )
{
	std::this_thread::sleep_for(5s);

	// 주스레드에 데이타를 보내고 싶을때 
	// pm.set_value 사용
	pm.set_value(100);
}

int main()
{
	// 2. 주스레드는 스레드 생성시 promise 객체를 참조로 전달
	std::promise<int> pm;
	std::thread t(&foo, std::ref(pm) ); // std::ref(pm) ==> pm을 참조로 보내 달라 

	// 3. promise 객체에서 미래의 결과를 담는 "future객체" 얻기
	std::future<int> fut = pm.get_future(); // 이순간은 블럭안됨

	// 4. 결과를 꺼내려면 future 멤버 함수 사용
	int ret = fut.get(); // 이순간 결과가 아직 없으면 대기(블럭)
						
	t.join();
}






