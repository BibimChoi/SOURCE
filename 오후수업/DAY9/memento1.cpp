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
	g.DrawLine(0, 0, 100, 100, Red, 5);
	g.DrawLine(20, 20, 30, 60, Red, 5);

	// 방법 2. Graphics 안에 선의 두께, 색상을 관리하는 멤버를 관리 - IOS 가 이 방식 입니다.
	g.SetStrokeColor(Red);
	g.SetStrokeWidth(5);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(20, 20, 30, 60);

//	g.DrawLine(20, 20, 30, 60, Blue, 3);

	// 방법 3. 선의 속성을 관리하는 Pen 클래스 도입
	Pen pen(Red, 5, DASH);
	g.DrawLine(20, 20, 30, 60, &pen);


	// 방법 4. 펜 객체를 Graphics가 보관하는 방식
	Pen pen(Red, 5, DASH);
	g.SetPen(&pen);						// Windows API에서 사용하는 GDI 라이브러리 개념
	g.DrawLine(20, 20, 30, 60);
}









