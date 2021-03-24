#include <iostream>

class Point { int x, y; };

//void foo(Point pt) {}      // call by value : 복사본의 오버헤드
//void foo(const Point& pt) {} // lvalue 와 rvalue를 모두 받을수 있다.

void foo(Point& pt) 
{
	std::cout << "lvalue, 인자로 받은 객체는 호출뒤에도 계속 살아 있다" << std::endl;
}
void foo(Point&& pt)
{
	std::cout << "rvalue, 인자로 받은 객체는 호출뒤에는 파괴된다." << std::endl;
}
int main()
{
	Point pt;
	foo(pt);
	foo(Point());
	
	Point&& r = Point(); // r은 lvalue 입니다. 이름이 있으므로
	foo(r);	
	///..... 이제 마지막으로 foo 에 전달하면, 더이상은 r이 필요 없다.
	foo(static_cast<Point&&>(r)); // 이순간 메모리상의 변화는 없습니다.
								// 단지, r을 foo(rvalue) 버전으로 보내달라는 요청일뿐

}

