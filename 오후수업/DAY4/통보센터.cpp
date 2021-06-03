#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	// 통보센터에 등록하는 함수는 반드시 인자가 void* 한개 이어야 한다는 규칙을
	// 만듭니다. - 규칙은 여러분이 변경해도 됩니다.
	using HANDLER = std::function<void(void*)>;

	std::map< std::string, std::vector<HANDLER> > notif_map;
public:

	void addObserver(std::string key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(std::string key, void* hint)
	{
		for (auto f : notif_map[key]) // notif_map[key] 는 결국 vector입니다.
			f(hint);				  // 등록된 모든 함수 호출(힌트도 전달)
									// f는 function 입니다.
	}

	// "global default center" 라는 개념을 만들어 봅시다(이 클래스 제작자가 만든개념)
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
	// 아래 처럼 사용자가 만들어도 되고(Local 통보센터)
	// NotificationCenter nc;		// 생성자를 private에 만들면 이코드가 안되게 할수
									// 있습니다. "singleton 개념, 다음주 주제"

	// 모든 팀원이 같이 사용하는 통보센터는 아래 처럼 꺼내서 사용하면 됩니다.
	NotificationCenter& nc = NotificationCenter::defaultCenter();



	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY",      std::bind(&goo, _1, 1) ); // goo(hint값, 1) 호출됨
	nc.addObserver("DISCONNECT-WIFI", std::bind(&goo, _1, 2) );

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




