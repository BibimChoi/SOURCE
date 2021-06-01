#include <mutex>
// 방법 3. 변하는 정책 클래스를 인터페이스가 아닌 템플릿 인자로 변경할수 있게 한다.
// => Policy Base Design(단위 전략) 이라는 기술

// 정책 클래스를 교체하는 기술

//					인터페이스 기반 교체				템플릿 기반 교체
// 성능				가상함수기반 - 느리다				인라인 함수 가능 - 빠르다
// 실행시간 교체		실행시간 정책 교체 가능			실행시간 교체 안됨.
// 약속된 함수이름	추상클래스 문법으로 코드로 표현	문서화 되어야 한다
//													"모든 동기화 정책은 lock/unlock 필요"
//													"named requierment 개념"



template<typename T, typename ThreadModel = NoLock > class List
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
//----------------------------------
// 템플릿 인자로 전달할 동기화 정책을 담은 클래스
class MutexLock
{
	std::mutex m;
public:
	inline void lock()   { m.lock(); }
	inline void unlock() { m.unlock(); }
};
class NoLock
{
public:
	inline void lock() {  }
	inline void unlock() { }
};
//----------------------------------------------
// 이제 List 사용시 "템플릿 인자로 동기화정책"을 전달합니다
//List<int, NoLock> st; 
//List<int, MutexLock> st;

List<int> st;

int main()
{
	st.push_front(10);
}




