#include <mutex> // C++ 표준이 제공하는 뮤텍스
// 정책 클래스를 교체하는 2가지 기술
// 1. 인터페이스 기반 교체 - 전통적인 객체지향 디자인 에서 사용
//				=> "strategy 패턴"

// 2. 템플릿 기반 교체 - C++만의 기술( 아주 널리 사용 )
//				=> Policy Base Design 이라고 합니다.

// 정책 클래스를 교체 할때
//					인터페이스기반 교체				템플릿 인자로 교체
// 1. 성능			가상함수기반 - 느리다.			인라인함수 - 빠르다.

// 2. 실행시 교체	실행시간 교체 가능				실행시간 교체 안됨

// 3. 함수 이름		인터페이스에 코드로 약속되어있다	문서화 해야 한다.


// 주의 !!! "STL" 이 아래 처럼되어 있는것은 아닙니다.
// STL의 list는 C++98 시절에 만들어서, 멀티스레드는 고려하지 않고 설계되었습니다

// "Webkit" 이라는 오픈소스의 list가 아래 처럼 만들어져 있습니다.



template<typename T, typename ThreadModel = NoLock> class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//......
		tm.unlock();
	}
};

// 이제 List의 템플릿 인자로 사용될 다양한 동기화 정책을 설계합니다.
struct NoLock
{
	inline void lock() {}
	inline void unlock() {}
};

struct MutexLock
{
	std::mutex m;
	inline void lock()   { m.lock(); }
	inline void unlock() { m.unlock(); }
};

//------------------------------------------------
// List<int, NoLock > st; 
// List<int, MutexLock > st;
List<int> st;


int main()
{
	st.push_front(10);
}




