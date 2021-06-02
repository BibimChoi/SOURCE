#include <iostream>
#include <Windows.h>

/*
DWORD __stdcall foo(void* p)
{
	std::cout << "foo" << std::endl;
	return 0;
}
int main()
{
	CreateThread(0, 0, foo, "A", 0, 0); // 윈도우에서 스레드 만드는 함수
									    // 리눅스 : pthread_create()
	getchar();
}
*/



// 스레드 개념을 객체지향으로 설계해 봅시다.
// 아래 클래스가 라이브러리 내부 클래스라고 가정
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0);  }

	// 핵심 1. 아래 함수가 static 멤버 함수이어야 하는 이유를 정확히 아셔야 합니다
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* pThis = static_cast<Thread*>(p);

		// 이제 pThis가 this 입니다. pThis만 있으면 모든 멤버에 접근 가능합니다.
		pThis->threadLoop();

//		threadLoop(); // error
						// this->threadLoop() 가 되고, 다시 객체는 인자처럼 생각하면
						// 되므로... threadLoop(this)가 되야 하는데..
						// this가 없다!

		return 0;
	}

	virtual void threadLoop() {  } // threadLoop( Thread* this)
};
// 위 코드가 왜 에러일까요 ?







// 아래 클래스는 라이브러리 사용자라고 가정
class MyThread : public Thread
{
public:
	virtual void threadLoop() { cout << "threadLoop" << endl; }
};

int main()
{
	MyThread t;
	t.run();	// 이순간 스레드가 생성되어서 threadLoop 수행
	getchar();
}

*/

