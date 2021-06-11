#include <iostream>
#include <thread>
#include <mutex>

// empty class : 아무 멤버도 없는 클래스, sizeof(empty class) => 1
//				 멤버가 없지만 하나의 독립된 타입이다.
//				 함수 오버로딩시 인자로 활용될수 있다.
class adopt_lock_t {};

adopt_lock_t adopt_lock;


//  RAII : Resource Acquision Is Initialization
//		   자원을 획득하는 것은 (자원관리객체) 초기화 될때 이다.
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); } // lock 을 사용하는 생성자
	lock_guard(T& m, adopt_lock_t) : mtx(m) {  }            // lock 을 하지 않은 생성자

	~lock_guard()             { mtx.unlock(); }
};

std::mutex m;

void foo()
{
//	lock_guard<std::mutex> g(m);

	// try_lock 등의 다른 방법으로 mutex를 획득한후..
	// 참고 : std::lock() 을 사용하면 여러개의 뮤텍스를 동시에 lock 할수 있습니다.
	if (m.try_lock())
	{
		lock_guard<std::mutex> g(m, adopt_lock);
		// ....

		//m.unlock(); // 이 부분만 자동으로 관리하고 싶다.
	}
}

int main()
{
	std::thread t(foo);
	t.join();
}
