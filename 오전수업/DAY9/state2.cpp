// 1_State1 - 182 page
#include <iostream>
using namespace std;

// 방법 1. 아이템에 따른 분기문(if) 작성
// ==> 새로운 아이템이 등장하면 분기문이 추가되어야 합니다.
// ==> 모든 동작(함수)에 분기문이 있어야 합니다.
class Charater
{
	int gold;
	int item;
public:
	void run() 
	{
		if ( item == 1)
			cout << "run" << endl; 
		else if ( item == 2 )
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







