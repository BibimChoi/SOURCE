#include <iostream>

// Decorator 패턴

// "객체"에 "동적으로 기능을 추가"하는 패턴..

// Decorator(포장지)는 객체에 기능을 추가하지만, 기능이 추가된 객체에도 다시 추가할수 있다.
// 재귀적 포함

// => 객체와 Decorator들은 동일 기반 클래스가 있어야 한다.

// GOF 패턴에서 "재귀적 포함"을 사용하는 것은 2개입니다.

// 그런데, "왜" 재귀적 포함을 사용하는가 ?

// Composite : 재귀적 포함을 사용한 복합객체 만들기
// Decorator : 재귀적 포함을 사용한 객체에 동적 기능추가

// 우주선(객체) 와 우주선에 기능을 추가하는 객체(Decorator, 포장지)
// 는 공통의 기반 클래스가 있어야 한다.
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

// LeftMissile 과 RightMissile 는 "우주선"은 아니다.
// 우주선에 기능을 추가하는 클래스
class LeftMissile : public Item 
{
	Item* ship;
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();  
		std::cout << "Fire Left Missile" << std::endl; 
	}
};
class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
//	ss.Fire();

	LeftMissile lm(&ss); 
//	lm.Fire();		

//	RightMissile rm(&ss);
	RightMissile rm(&lm); // 기능이 추가된 객체에 다시 기능 추가
	rm.Fire();
}

