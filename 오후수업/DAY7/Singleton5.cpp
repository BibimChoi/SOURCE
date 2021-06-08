#include <iostream>
#include <mutex>

// 동기화 자원을 사용할때는 RAII기술(생성자/소멸자에서 lock/unlock) 로 해야 합니다.

template<typename T>
class lock_guard
{
//	std::mutex& mtx; // 이렇게 할수도 있지만.. 하지 않은 이유는
	T& mtx;			// C++ 표준에 뮤텍스는 6가지 종류가 있습니다.
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()			  { mtx.unlock(); }
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
		// lock/unlock 을 직접하면
		// 1. 실수로 unlock 을 안하면..deadlock
		// 2. 예외가 발생하면 deadlock
		//mtx.lock();
		
		//lock_guard<std::mutex> lg(mtx); // 내부적으로 mtx를 참조로 보관하고
										// 생성자에서 lock() 수행
										// 핵심 ) 함수 수행중 예외가 발생해도
										//   지역변수는 안전하게 파괴 되므로 lg의소멸자
										//    는 호출됩니다.(unlock)을 보장!

		std::lock_guard<std::mutex> lg(mtx); // C++11 표준에 이미 lock_guard가 있습니다.

		if (sinstance == nullptr)
			sinstance = new Cursor;

		//mtx.unlock();

		return *sinstance;
	}



};
Cursor* Cursor::sinstance = nullptr;
std::mutex  Cursor::mtx;






int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;
}











