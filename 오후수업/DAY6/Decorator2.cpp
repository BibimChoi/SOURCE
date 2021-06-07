// codexpert.org에서 DAY6.zip 받으시면 됩니다.

// 1. "x86", "Debug"

// 2. Windows SDK 버전 설정해 주세요.












// 1_Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속 : 객체에 대한 기능 추가가 아니라 "클래스에 기능 추가"
//		 실행시간 추가가 아닌 "코딩 작성"시 기능 추가

// 포함 : 객체에  기능 추가
class LeftMissile 
{
	SpaceShip* ship; // 포함(포인터 또는 참조로..)
					// 외부에 존재하는 우주선(객체)를 가리킨다.
public:
	LeftMissile( SpaceShip* s ) : ship(s) {}

	void Fire()
	{
		ship->Fire();  // 객체의 원래 기능 수행
		std::cout << "Fire Left Missile" << std::endl; // 추가 기능 수행
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);  // ss라는 이미 존재하는 객체에 기능을 추가하는 코드
	lm.Fire();			// 1. ss.Fire() 수행(본래 객체의 기능 수행)
						// 2. 추가 기능(Left Missile) 수행
}

