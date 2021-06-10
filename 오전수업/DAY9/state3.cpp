#include <iostream>
using namespace std;

// 방법 2. 변하는 것은 가상함수로!

class Charater
{
	int gold;
	int item;
public:
	void run() { doRun(); }
	void attack() { doAttack(); }

	virtual void doRun()    { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};
class PowerItem : public Charater
{
public:
	void doRun()   override { std::cout << "fast run" << std::endl; }
	void doAttack()override { std::cout << "power attack" << std::endl; }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new PowerItem; // 아이템 획득
	p->run();
	p->attack();

	// 그런데, 위코드는 기존 객체의 동작이 변경된것이 아니라.!!
	// 동작이 변경된 새로운 캐릭터가 생성된것!
	// 캐릭터의 동작 뿐 아니라 상태로 변경되었다.(새로운 캐릭터!!!)
}

// Decorator : 기능의 "추가" => 기존 기능이 유지되면서 새로운 기능을 추가 하는 것
// 지금 주제 : 동작의 "변경" => 추가 가 아니라 변경되는 것



