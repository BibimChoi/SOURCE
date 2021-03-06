#include <iostream>
using namespace std;

// 핵심 
// 1. 아이템을 획득해도 캐릭터가 가진 상태(멤버 데이타)는 변하지 않는다.
// 2. 아이템에 따라 동작(멤버함수)는 변경되어야 한다.
//    즉, 새로운 객체는 아니고, 동작(멤버 함수)만 변경하고 싶다.

// 캐릭터의 상태(아이템여부)에 따라 변해야 하는 멤버함수를 인터페이스로 설계 한다.
struct IStateAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IStateAction() {}
};

class Charater
{
	int gold;
	int item;
	IStateAction* pAction = nullptr;
public:
	void setAction(IStateAction* p) { pAction = p; }

	void run()    { pAction->run(); }
	void attack() { pAction->attack(); }
};

// 각 아이템 별로 동작을 정의 합니다.
// 새로운 아이템이 만들어지만, 아래와 같은 클래스만 추가되면 됩니다.
class NormalState : public IStateAction
{
public:
	virtual void run()    { std::cout << "run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};
/*
class RedItemState : public IStateAction
{
public:
	virtual void run() { std::cout << "fast run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};
class BlueItemState : public IStateAction
{
public:
	virtual void run() { std::cout << "fast run" << std::endl; }
	virtual void attack() { std::cout << "power attack" << std::endl; }
};
*/
// 각 아이템에 따른 동작은 표준 상태에서 상속 받은후..
// 변경할 항목만 재정의 해도 됩니다.
class RedItemState : public NormalState
{
public:
	virtual void run() { std::cout << "fast run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};
class BlueItemState : public NormalState
{
public:
	virtual void run() { std::cout << "fast run" << std::endl; }
	virtual void attack() { std::cout << "power attack" << std::endl; }
};

int main()
{
	// 상태에 따라 동작을 정의한 객체를 생성합니다.
	// 이런 객체들은 멤버 데이타는 없고 함수는 있는 경우가 많아서 "싱글톤"으로 해도 됩니다.
	NormalState s1;
	RedItemState s2;
	BlueItemState s3;
	
	Charater* p = new Charater;
	p->setAction(&s1);
	p->run();
	p->attack();

	// 아이템 획득에 따른 동작을 변경합니다.
	// 객체는 마치 다른 클래스를 사용하는 것처럼 보이게 됩니다.
	// (멤버 데이타는 변하지 않지만, 멤버 함수가 변경되므로)
	p->setAction(&s2);
	p->run();
	p->attack();

	p->setAction(&s3);
	p->run();
	p->attack();

	// 특징 : 동일한 객체에 멤버 함수를 실행시간에 변경해 주는 것
}

// 디자인 패턴에서..
// 변하는 것을 다른 클래스로 뽑아서 인터페이스 기반 교체를 사용하는 패턴은 3가지 입니다.

// 전략패턴(strategy) : 여러개의 알고리즘이 존재 할때 알고리즘을 캡슐화 해서 
//						알고리즘을 실행시간에 교체 할수 있게 한다.
//						Edit/IValidator		
//						바둑게임/다음수예측알고리즘(초급, 중급, 고급)
//						"동작" 전체에 대한 교체는 아니고
//						알고리즘(전략)을 교체 하는 것.

// 상태패턴(state)    : 객체의 상태에 따라 동작(거의 모든 멤버 함수)를 변경하는 것
//					   모든 멤버함수(동작)이 변경되므로 마치 다른 클래스를 사용하는 것처럼 보인다.
//					   단, 멤버데이타(객체의 상태)는 유지된다.

// 빌더(builder) : 복잡한 객체를 만들때 "동일한 공정"을 사용하지만 "각 공정의 표현" 이 다른 객체 생성
//					객체를 생성할때 사용하는 패턴
