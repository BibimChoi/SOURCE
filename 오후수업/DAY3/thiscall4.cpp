#define USING_GUI
#include "cppmaster_gui.h""
#include <map>

/*
void foo(int id)
{
	std::cout << "foo : " << id << std::endl;
}

int main()
{
	int id1 = ec_set_timer(1000, foo);
	int id2 = ec_set_timer(500, foo);

	ec_process_message(); // 종료되지 말고 타이머를 처리해 달라!
}
*/





// 타이머 개념을 클래스 만들때 사용해 봅시다.

class Clock;
std::map<int, Clock*> this_map; // 타이머 id를 키값으로 this 포인터 보관하는 맵

class Clock
{
	string name;
public:
	Clock(string s) : name(s) {}

	void Start(int ms)
	{
		int id = ec_set_timer(ms, timerHandler);

		// this 포인터를 자료구조에 보관한다.
		this_map[id] = this;
	}

	// 핵심 1. 아래 함수가 static 멤버인 이유를 알아야 합니다.
	// 2. 
	static void timerHandler(int id)
	{
//		std::cout << name << std::endl; // this->name 이 되어야 하는데 this가 없습니다

		// 자료구조에 보관된 this를 꺼내면, 모든 멤버에 접근할수 있습니다.
		Clock* pThis = this_map[id];

		std::cout << pThis->name << std::endl;
	}
};




int main()
{
	Clock c1("AAA");
	Clock c2("\tBBB");

	c1.Start(1000); // 1초에 한번씩 자신의 이름을 주기적으로 출력!
	c2.Start(500);  

	ec_process_message();
}





