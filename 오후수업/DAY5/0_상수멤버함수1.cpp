// 0_상수멤버함수
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
	void set(int a, int b) { x = a; y = b; }

	// 상수 멤버 함수의 의도 : 함수가 내부적으로 멤버의 값을 변경하지 않는다는것을
	//						   컴파일러에게 알려주는것
	//	"상수 객체 라도 호출할수 있게 해달라는 의미"
	//  "상수 객체는 상수 멤버 함수만 호출할수 있다"

	void print() const	// 상수 멤버 함수
	{
//		x = 10;		// error. 상수 멤버 함수 에서는 모든 멤버를 상수 취급

		cout << x << ", " << y << endl; // ok. 멤버를 읽는 것은 가능
	}
};  

int main()
{
	const Point pt(1, 2); // 상수 객체 입니다.

	pt.x = 10;		// error. public 에 있지만 상수객체 이므로
	pt.set(10, 20);	// error.
	pt.print();		// error. - 상수 멤버 함수가 아니라면
					// ok.. - 상수 멤버 함수로 만들면
}    
