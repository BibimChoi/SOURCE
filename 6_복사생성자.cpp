// C++ 기본에서 배우는 복사 생성자를 완벽히 이해해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자를 만들어 봅시다.
	// 1. call by value
	Point(Point pt) {}
};

int main()
{
	Point p1;		// 1번 생성자 호출
	Point p2(1, 2); // 2번 생성자 호출
	Point p3(p2);	// 인자가 한개인 생성자 필요
					// 컴파일러가 만들어 주는 복사 생성자 사용 Point(const Point&)
					
}
