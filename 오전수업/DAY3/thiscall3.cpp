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
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 핵심 1. 아래 함수가 왜 static 멤버 함수가 되어야 하는지 정확히 알아야 합니다
	// 
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p); 

		// 이제 self 가 결국 this 입니다.. self 를 사용하면 모든 멤버에 접근 가능합니다.
		self->threadLoop(); // ok..
							// 결국.  threadLoop(self) 가 됩니다


//		threadLoop(); // this->threadLoop() 가 되고
					  // 다시, 객체는 결국 인자 이므로
					  // threadLoop(this) 로 호출되어야 하는데...
					  // static 멤버 함수에는 this가 없습니다.
					  // 그래서 error 입니다

		return 0;
	}


	virtual void threadLoop() {  } // threadLoop( Thread*  this)
};
// 위 코드는 왜 에러일까요 ?



// 라이브러리 사용자 클래스
class MyThread : public Thread
{
public:
	virtual void threadLoop() { cout << "threadLoop" << endl; }
};

int main()
{
	MyThread t;
	t.run();	// 이순간 스레드가 생성되어서 threadLoop() 가상함수가 실행되어야 합니다.

	getchar();
}

*/

