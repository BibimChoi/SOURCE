#include <mutex> // C++ 표준이 제공하는 뮤텍스
// 정책 클래스를 교체하는 2가지 기술
// 1. 인터페이스 기반 교체 - 전통적인 객체지향 디자인 에서 사용
// 2. 템플릿 기반 교체 - C++만의 기술( 아주 널리 사용 )

template<typename T, typename ThreadModel > class List
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


List<int, NoLock > st; 


int main()
{
	st.push_front(10);
}




