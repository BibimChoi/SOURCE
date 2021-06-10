// 8_메멘토 - 178
#include <iostream>
using namespace std;

// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
};

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.
	// 방법 1. 함수의 인자로 전달하자.
	g.DrawLine(0, 0, 100, 100, 5, Red);
	g.DrawLine(30, 30, 70, 50, 5, Red);

	// 방법 2. Graphics 객체안에 펜의 색, 두께 등을 관리하는 멤버데이타를 넣자
	g.SetStrokeColor(Red);
	g.SetStrokeWidth(5);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(30, 30, 70, 50);

	// 방법 3. 색, 두께를 별도로 관리하지 말고, Pen 을 도입하자.
	Pen pen(Red, 5, DASH);
	g.DrawLine(0, 0, 100, 100, pen);

	// 방법 4. Graphics 안에 Pen* 를 관리
	Pen pen(Red, 5, DASH);
	g.SetPen(&pen);
	g.DrawLine(0, 0, 100, 100);
}
// 위코드는 memento 패턴과는 관련없이.. 
// 그냥 Graphics 라는 클래스를 설계할때 위 처럼 다양하게 생각할수 있다는 소개 입니다.
