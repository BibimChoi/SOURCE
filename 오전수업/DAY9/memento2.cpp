#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graphics
{
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
		penWidth = p->penWidth;
		penColor = p->penColor;
	}


	void DrawLine(int x1, int y1, int x2, int y2)
	{
		// penWidth 와 penColor 를 사용해서 선그리는 작업
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

	int token = g.SaveState(); // 객체의 현재 상태를 저장했다 복구 할수 있게 한다.
				               // memento 패턴!

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	// 아래 처럼 다시 설정하는 것은 복잡하고 번거롭니다. set..이 여러줄이다.
//	g.SetStrokeColor(0);
//	g.SetStrokeWidth(10); 

	g.RestoreState(token);

}









