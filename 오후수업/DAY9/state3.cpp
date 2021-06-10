// 1_State1 - 182 page
#include <iostream>
using namespace std;

// 방법 3. 변하는 것을 가상함수로

class Charater
{
	int gold;
	int item;
public:
	void run()    { doRun(); }
	void attack() { doAttack(); }

	virtual void doRun()    { std::cout << "run" << std::endl; }
	virtual void doAttack() { std::cout << "attack" << std::endl; }
};

// 아이템 획득에 따른 동작변경을 위해 파생 클래스 설계
class PowerItemCharacter : public Charater
{
public:
	void doRun()    override { std::cout << "fast run" << std::endl; }
	void doAttack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	// 아이템 획득
	p = new PowerItemCharacter;	// 기존 캐릭터의 동작 변경이 아니라.
								// 새로운 객체
	p->run();
	p->attack();
}






