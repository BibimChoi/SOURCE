#include <iostream>
using namespace std;

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

// 사용자가 IMP3를 직접 사용하게 하지말고
// 중간층을 만들어서 사용하게 하자.

class MP3
{
	IMP3* pImpl;
public:
	MP3(IMP3* p = nullptr) : pImpl(p)
	{
		if (pImpl == nullptr)
			pImpl = new IPod;
	}
	// 함수의 모든 기능을 구현부에 의존한다
	void Play() { pImpl->Play(); }
	void Stop() { pImpl->Stop(); }

	// 사용자 요구 조건을 중간층에서 해결할수 있다면
	// 여기서 해결
	void PlayOneMinute()
	{
		pImpl->Play();
		// 1분후에
		pImpl->Stop();
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
};

int main()
{
	People p;
	MP3 mp3;   // 이 클래스 자체는 MP3의 구현 기능이 없습니다.
				// 단지, 함수 이름만 Client에 제공하고, 구현은 IMP3 사용
	p.Use(&mp3);

//	IPod pod;
//	p.Use(&pod);
}


