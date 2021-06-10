#include <iostream>
using namespace std;

// 목표 : 캐릭터 객체의 변경이 아니라.. 기존 객체에 대해 동작(멤버 함수만)만 변경되어야 한다.
//	     객체의 상태(멤버 데이타)는 계속 유지 되어야 한다.

// 방법 3. 변하는 것을 다른 클래스로 - 가장 좋은 방식

// 아이템 획득에 따라 변해야 하는 동작(멤버함수)를 모두 인터페이스 설계
struct ItemAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~ItemAction() {}
};
class Charater
{
	int gold;
	int item;

	ItemAction* pAction = nullptr;
public:
	void setAction(ItemAction* p) { pAction = p; }

	void run()    { pAction->run(); }
	void attack() {	pAction->attack(); }
};

// 이제 아이템에 따른 동작을 정의 하면 됩니다.
// 새로운 아이템이 추가되어도 아래처럼 클래스만 만들면 됩니다.
// 특징 : 상태(멤버데이타)는 없고 동작(멤버함수)만 있습니다.
class NormalAction : public ItemAction
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

/*
class RedItemAction : public ItemAction
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class BlueItemAction : public ItemAction
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
*/

// NormalAction 에서 상속받으면 기본 동작을 상속 받으므로
// Item 에 따라 변경할 동작만 정의하면 됩니다.
class RedItemAction : public NormalAction
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
};
class BlueItemAction : public NormalAction
{
public:
	void attack() override { std::cout << "power attack" << std::endl; }
};
int main()
{
	NormalAction s1;
	RedItemAction s2;
	BlueItemAction s3;

	Charater* p = new Charater;
	p->setAction(&s1);
	p->run();
	p->attack();

	// 아이템 획득시 동작을 변경하기위해 Action 객체를 변경합니다.
	p->setAction(&s2);
	p->run();
	p->attack();

	p->setAction(&s3);
	p->run();
	p->attack();

}
