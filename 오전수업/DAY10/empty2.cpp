#include <iostream>
#include <thread>
#include <mutex>

// empty class : 아무 멤버도 없는 클래스, sizeof(empty class) => 1
//				 멤버가 없지만 하나의 독립된 타입이다.
//				 함수 오버로딩시 인자로 활용될수 있다.
class adopt_lock_t {}; // lock 이 된 뮤텍스를 받을때
//class defer_lock_t {}; // 나중에 lock을 하겠다...

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
		//lock_guard<std::mutex> g(m, adopt_lock);

		std::lock_guard<std::mutex> g(m, std::adopt_lock);

//		std::adopt_lock_t  aaaa;
//		std::lock_guard<std::mutex> g(m, aaaa);
		

		// ....

		//m.unlock(); // 이 부분만 자동으로 관리하고 싶다.
	}
}

int main()
{
	std::thread t(foo);
	t.join();


	int* p1 = new int[1000]; // 메모리 할당 실패시 => "std::bad_alloc" 예외 발생
	int* p2 = new(nothrow) int[1000]; // 메모리 할당 실패시 => nullptr(0) 반환
}
// 1. 옵션으로 처리
void foo(int option)
{
	if (option == 1) {}
	if (option == 2) {}
}
// 2. 오버로딩으로 처리
void foo() {}
void foo(std::adopt_lock_t a) {}
void foo(std::defer_lock_t a) {}

// new는 함수 인가요 ? 연산자 인가요 ?

// new는 연산자!!
// new가 하는일
// 1. operator new()라는 함수를 호출해서 메모리 할당
// 2. 생성자 호출..

/// new int
//  => operator new (sizeof(int)) 호출
//  => 즉, operator new(std::size_t) 모양의 함수가 호출

/// new(nothrow) int
//  => operator new(sizeof(int), nothrow) 호출..
//  => 즉, operator new(std::size_t, std::nothrow_t) 모양의 함수가 호출










