#include <iostream>
#include <thread>
#include <mutex>

// empty class : 아무 멤버도 없는 클래스
//				sizeof(adopt_lock_t) ===> 1 
//				아무런 멤버도 없지만 "하나의타입" 이므로 함수 오버로딩에 사용될수 있다.
class adopt_lock_t {};

adopt_lock_t adopt_lock;

// RAII ( Resource Acquision Is Initialization )
//        리소스를 획득하는 것은 (리소스 관리 객체)가 초기화 될때 이다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m)                : mtx(m) { mtx.lock(); }
	lock_guard(T& m, adopt_lock_t ) : mtx(m) { }
	~lock_guard()             { mtx.unlock(); }
};

std::mutex m;

void foo()
{
//	lock_guard<std::mutex> g(m); // 생성자에서 m.lock 수행

	// try_lock() 또는 다른 방식으로 뮤텍스를 lock 하고( std::lock() )
	if (m.try_lock())
	{
		// unlock 을 위해서만 lock_guard를 사용하고 싶다.
	//	lock_guard<std::mutex> g(m, adopt_lock);
	//	lock_guard<std::mutex> g(m, {}); // adopt_lock_t 가 explicit 생성자가 아니면
											// 이 표기법 허용

		std::lock_guard<std::mutex> g(m, std::adopt_lock); //ok
		std::lock_guard<std::mutex> g(m, {}); // error. explicit 생성자

		//....
	
	}
}




int main()
{
	std::thread t(foo);
	t.join();
}
