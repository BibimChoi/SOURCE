// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;

// 인터페이스를 사용하면 다양한 MP3 장비로 교체 할수 있다.

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
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


