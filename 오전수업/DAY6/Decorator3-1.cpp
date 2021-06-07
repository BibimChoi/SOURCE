#include <iostream>

// 재귀적 포함(자신이 자신을 포함)하는 디자인 패턴은 2가지 입니다.

// Composite : 재귀적 포함을 사용해서 "복합 객체" 를 만드는 패턴

// Decorator : 재귀적 포함을 사용해서 "객체"에 기능을 추가하는 패턴



// Decorator : 객체에 기능을 추가하는 패턴

// 포장지(기능추가 객체)는 사물을 포장(객체에 기능추가)하지만
// 포장된 객체를 다시 포장할수 있다.

// 재귀적 포함을 사용한 기능의 추가

// 객체(우주선)과 기능 추가객체는 동일한 기반 클래스가 있어야 한다.

struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};

class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
//------------------------------------
// 기능 추가 객체들은 공통의 특징이 있습니다.(Item* ship, 생성자 초기화등)

// Decorator 관련 용어(GoF 책)
// Decorator : 기능 추가 객체의 공통의 기반 클래스
// Concrete Decorator : 실제 기능 추가 객체들..
class Decorator : public Item
{
protected:
	Item* ship;
public:
	Decorator(Item* s) : ship(s) {}
	
	// 여기에는 Fire() 구현이 없으므로 추상 클래스 입니다.
};

class LeftMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};
class RightMissile : public Decorator
{
public:
	using Decorator::Decorator;

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;

	LeftMissile lm(&ss);

	RightMissile rm(&lm);
	rm.Fire();
}
