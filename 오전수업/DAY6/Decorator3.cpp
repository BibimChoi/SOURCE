#include <iostream>

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
	RightMissile rm(&lm); // 기능이 추가된 객체에 다시 기능을 추가할수 없을까 ?
	rm.Fire();
}
