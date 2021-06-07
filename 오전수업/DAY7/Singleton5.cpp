#include <iostream>
#include <mutex>

// 동기화 객체를 사용시 lock/unlock 을 직접하게 되면
// deadlock 의 위험이 있습니다
// RAII 기술을 사용해서 관리합니다(생성자/소멸자로 관리)

template<typename T> 
class lock_guard
{
	T& mtx;
	//std::mutex& mtx; // 이렇게 하지 않은 이유는, C++표준 뮤텍스가 무려 6가지가 있습니다.
					   // 그래서 템플릿으로 합니다.
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }   // 생성자에서 lock 수행
	~lock_guard()             { mtx.unlock(); } // 소멸자에서 unlock
};


class Cursor
{
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static std::mutex mtx;
	static Cursor* sinstance;
public:


	static Cursor& getInstance()
	{		
//		lock_guard<std::mutex> lg(mtx); // mtx를 lg라는 지역변수 객체로 관리 합니다.
										// 생성자에서 mtx.lock() 수행
										// 핵심 ) 함수 에서 예외 발생시 지역변수는 안전하게 파괴
										//		되므로 mtx.unlock()이 보장됩니다
										// stack unwinding(stack 풀기)라고 불리는 개념.

		std::lock_guard<std::mutex> lg(mtx); // C++ 표준에 이미 있습니다.

//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;

//		mtx.unlock();
//	    함수 종료시 지역변수인 lg의 소멸자에서 unlock() 수행		
		return *instance;
	}



};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;





int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << ", " << &c2 << std::endl;

}
