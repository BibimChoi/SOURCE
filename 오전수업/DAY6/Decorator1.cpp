// codexpert.org 에서 DAY6.zip 받으시면 됩니다.

// ID : 이메일,  PASS : 123456

// Windows SDK 버전 설정해 주세요

// "Debug", "x86"


















// 1_Decorator - 65 page
#include <iostream>

// 객체에 동적인 기능 추가를 생각해 봅시다

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능 추가
// 상속 : 객체에 대한 기능 추가가 아니라 클래스에 대한 기능 추가 이다.
//       실행시간에 동적 기능 추가가 아니라. 코드 작성시 기능의 추가이다.
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 원래 기능 사용
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm;
	lm.Fire();
}

