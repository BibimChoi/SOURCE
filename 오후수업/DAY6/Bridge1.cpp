// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// 1. 클래스 이름을 직접 사용 : 강한결합, 교체불가능하다.
// 2. 인터페이스 이름 사용 : 약한 결합, 교체가능한 설계

struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};
class IPod : public IMP3
{
public:
	void Play() { cout << "Play MP3 with IPod" << endl; }
	void Stop() { cout << "Stop" << endl; }
};
class People
{
public:
	void Use(IMP3* p)
	{
		p->Play();
		p->Stop();

		// 요구사항이 생겼다..
		// 그런데, 인터페이스를 변경하는 것은 아주 어렵다.
		// 인터페이스를 구현한 모든 클래스를 변경해야 한다.
		p->PlayOneMinute(); // 클라이언트가 이 함수를 요구한다.
	}
};


int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


