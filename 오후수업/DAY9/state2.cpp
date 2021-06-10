// 1_State1 - 182 page
#include <iostream>
using namespace std;

// 방법 1. item의 종류에 따른 조건 분기(if 또는 switch)
// ===> 동작이 많은 경우 복잡해 진다.
// ===> 새로운 아이템이 추가되면 모든 동작 함수가 변경되어야 한다.

class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if ( item == 1 )
			cout << "run" << endl; 
		else if (item == 2)
			cout << "fast run" << endl;
	}
	void attack() 
	{
		if ( item == 1)
			cout << "attack" << endl; 
		else if (item == 2)
			cout << "power attack" << endl;
	}
};



int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



