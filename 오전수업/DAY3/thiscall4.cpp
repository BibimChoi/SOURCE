#define USING_GUI
#include "cppmaster_gui.h""
#include <map>

/*
// ec_set_timer 에 2번째 인자로 전달되는 함수는 반드시 인자가 
// int 한개이어야 합니다.
void foo(int id)
{
	std::cout << "foo : " << id << std::endl;
}

int main()
{
	int id1 = ec_set_timer(1000, foo); // 1초에 한번씩 foo를 호출해 달라는것
	int id2 = ec_set_timer(500,  foo);

	ec_process_message(); // 종료되지 말고 타이머를 처리해 달라!
}
*/


// 타이머 개념을 C++ 클래스 에서 사용해 봅시다.
class Clock;	// 클래스 전방 선언

std::map<int, Clock*> this_map;

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms)
	{
		int id = ec_set_timer(ms, timerHandler);

		// this 포인터를 자료구조에 보관합니다.
		this_map[id] = this;
	}

	// 핵심 1. 아래함수는 반드시 static 멤버 함수이어야 합니다.( ec_set_timer에 전달되는
	//			함수는 인자가 int 한개 이어야 한다는 규칙이 있습니다.)
	static void timerHandler(int id)
	{
//		std::cout << name << std::endl; // this->name 이 되야 하는데 this가 없으므로
										// error

		// 자료구조에 보관된 this를 꺼내서 사용하면 모든 멤버에 접근할수 있습니다.
		Clock* self = this_map[id];

		std::cout << self->name << std::endl;
	}
};



int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000); // 1초에 한번씩 자신의 이름을 주기적으로 출력해야 합니다.
	c2.Start(500);  // 0.5초에 한번씩 자신의 이름을 주기적으로 출력해야 합니다.

	ec_process_message();
}



// C언어의 "Call Back" 함수를 C++로 구현하는 경우 반드시 static 멤버함수로 해야 합니다.
// 그런데, static 멤버함수는 this가 없으므로 다른 멤버 접근이 안됩니다.

// static 멤버 에서 this를 사용하려면 아래 2가지 방법이 널리 사용됩니다.
// 1. call back 함수의 인자로 this 전달 - CreateThread(0,0, foo, this, 0, 0)

// 2. this를 자료구조에 보관 - Clock 예제

