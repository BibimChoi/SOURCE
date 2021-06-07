// 6_Bridge1 - 90 page
#include <iostream>
using namespace std;
// Bridge 패턴
// 구현(IMP3와 MP3와 기계들)과 추상(MP3)을 분리해서 
// 상호 독립적인 UPDAE 가 가능하게 한다.

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
//--------------------
// 변경이 자주 발생하면 객체를 직접 사용하지말고 중간층을 도입해라
class MP3
{
	IMP3* mp3;
public:
	MP3(IMP3* p = nullptr) : mp3(p)
	{
		if (mp3 == nullptr) mp3 = new IPod;
	}
	// 실제 함수 구현은 구현객체에 위임
	void Play() { mp3->Play(); }
	void Stop() { mp3->Stop(); }
	void PlayOneMinute()
	{
		mp3->Play();
		// 1분 뒤에
		mp3->Stop();
	}
};

class People
{
public:
	void Use(MP3* p)
	{
		p->Play();
		p->Stop();
		p->PlayOneMinute();
	}

	/*
	void Use(IMP3* p)
	{
		p->Play();
		p->Stop();

		// 그런데... 사용자가 아래의 함수를 요구한다.
		// 인터페이스를 수정해야 한다. 복잡해 진다.
		p->PlayOneMinute();
	}
	*/
};
int main()
{
	People p;
	MP3 mp3;
	p.Use(&mp3);

	//IPod pod;
	//p.Use(&pod);
}


