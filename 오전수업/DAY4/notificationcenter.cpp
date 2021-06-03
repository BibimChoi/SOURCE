#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER> > notif_map;
public:
	
	void addObserver(std::string key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}
	void postNotificationWithName(std::string key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] 는 결국 vector 입니다
		{
			f(hint); // 등록된 모든 핸들러 호출(f 는 function 이므로 () 로 호출)
		}
	}

	// 오직 한개만 존재하는 "global default center" 개념을 만들어 봅시다
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter center;
		return center;
	}
};

void foo(void* p)        { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS(Cocoa 라이브러리)에 "통보센터"라는 개념이 있습니다.
	// 아래 처럼 사용자가 만들어도 되고(Local 통보센터)
	// NotificationCenter nc;	

	// 아래 처럼 하면 오직 한개만 존재하는 global 통보센터를 얻을수 있습니다.
	NotificationCenter& nc = NotificationCenter::defaultCenter();


	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0) );
	nc.addObserver("DISCONNECT-WIFI", std::bind(&goo, _1, 1));

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




