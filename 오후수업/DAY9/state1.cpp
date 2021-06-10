// 1_State1 - 182 page
#include <iostream>
using namespace std;

// Decorator : 기존 객체에 "기능의 추가"
//			   "파일 쓰기" ===> "압축해서 파일 쓰기"

// 지금 주제는 : 객체의 동작이 "변경" 에 대한 이야기


// 게임의 캐릭터를 생각해 봅시다.
// Item 획득에 따라 기존 캐릭터의 다양한 동작을 변경하고 싶다.
class Charater
{
	int gold;
	int item;
public:
	void run()    { cout << "run" << endl; }
	void attack() { cout << "attack" << endl; }
};
int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



