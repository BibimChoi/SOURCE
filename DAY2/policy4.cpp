#include <mutex>
// 방법 3. 변하는 정책 클래스를 인터페이스가 아닌 템플릿 인자로 변경할수 있게 한다.
// => Policy Base Design(단위 전략) 이라는 기술

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
List<int, NoLock> st; 

int main()
{
	st.push_front(10);
}




