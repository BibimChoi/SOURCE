// 방문자 패턴의 의미!!
class Shape
{
	virtual void Draw() = 0;
};
class Rect : public Shape {};
class Circle : public Shape {};

// 전통적인 객체지향 디자인 - 쉽다 , 어렵다로 답해 보세요
// 클래스의 추가    :  쉽다..(다형성을 잘 지켜서 코드를 작성했다면)
//							( p->Draw(), p->Clone())
// 가상 함수의 추가 :  어렵다. Shape 에 Move를 추가하는 순간
//						많은 도형의 코드가 수정되어야 한다.


// 방문자 패턴으로 디자인 하면
std::vector<Shape*> v;

MoveShapeVisitor msv; // 컨테이너에 있는 모든 도형을 이동하는 방문자
v.Accept(&msv);		  // Move 가상함수의 역활을 수행하는 방문자.

// 클래스의 추가 : 어려워 진다. 새로운 클래스가 추가 되면
//					방문자 인터페이스를 수정해야 한다.

// 함수의 추가   : 쉽다.(진짜 함수를 추가하는 것이 아니라.
//						함수가 하는일을 방문자가 한다는 의미)




