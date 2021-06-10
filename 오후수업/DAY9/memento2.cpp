// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graphics
{
	// 반드시 저장되어야 하는 멤버를 별도의 구조체로 설계
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::map<int, Memento*> memento_map;

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
public:
	int SaveState()
	{
		static int key = 0;
		++key;

		Memento* p = new Memento;
		p->penColor = penColor;
		p->penWidth = penWidth;

		memento_map[key] = p;

		return key;
	}
	void RestoreState(int key)
	{
		Memento* p = memento_map[key];

		penColor = p->penColor;
		penWidth = p->penWidth;
	}

	// 빌드시 : /std:c++17 옵션 필요 
	void ClearMemento()
	{		
		// map : pair를 저장하는 tree 입니다.
		/*
		for (auto e : memento_map)
		{
			// 현재 e는 pair 입니다.
			delete e.second;
		}
		*/
		// C++17 structure binding 문법
		for (auto[key, p] : memento_map)
		{
			delete p;
		}
		memento_map.clear();
	}

	~Graphics() { ClearMemento(); }


	void DrawLine(int x1, int y1, int x2, int y2)
	{
		// penWidth, penColor 를 사용해서 그리기.
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};






int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.SaveState();   // 객체의 상태를 저장했다가, 복구 할수 있도록 하자.
					 // "Memento" 패턴
					// 캡슐화/정보은닉 을 위해 하지 않고, 객체의 상태를 저장하는 패턴

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	// g.SetStrokeColor(0);
	// g.SetStrokeWidth(10);

	g.RestoreState(token); // 저장했던 상태를 복구
	g.RestoreState(token);
}









