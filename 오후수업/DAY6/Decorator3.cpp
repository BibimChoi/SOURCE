#include <iostream>


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

