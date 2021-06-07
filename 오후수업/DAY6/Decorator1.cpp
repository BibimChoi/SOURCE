// codexpert.org에서 DAY6.zip 받으시면 됩니다.

// 1. "x86", "Debug"

// 2. Windows SDK 버전 설정해 주세요.












// 1_Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
// 상속 : 객체에 대한 기능 추가가 아니라 "클래스에 기능 추가"
//		 실행시간 추가가 아닌 "코딩 작성"시 기능 추가

class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 원래 있던 기능 사용
		std::cout << "Fire Left Missile" << std::endl; // 추가된 기능
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; // ss라는 우주선(객체)에 기능이 추가된것이 아니라
					// 기능이 추가된 새로운 우주선을 만든것
	lm.Fire();
}

