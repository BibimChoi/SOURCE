#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// 스레드간 통신
// promise & future


int foo()
{
	std::this_thread::sleep_for(5s);

	return 100;
}

int main()
{
	// 결론 : 간단한 비동기 작업이 필요하면 thread 클래스를 사용하지 말고
	//        async 함수를 사용해라
	std::future<int> f1 = std::async(std::launch::async, foo);
//	std::future<int> f2 = std::async(std::launch::async, goo);

	int n = f.get();
}


