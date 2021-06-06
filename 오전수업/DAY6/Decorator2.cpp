
#include <iostream>

class SpaceShip
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속 : 클래스에 기능 추가
// 포함 : 객체에 기능 추가

class LeftMissile 
{
	SpaceShip* ship; // 포함(포인터 또는 참조로)
					// 포인터 이므로 외부에 이미 존재하는 우주선을 가리킬수 있다
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire(); // 외부에 있는 객체의 기능 사용
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능 추가
	}
};
int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss); // ss 라는 이미 존재하는 객체에 lm 의 가진 기능을 추가
	lm.Fire();
}
