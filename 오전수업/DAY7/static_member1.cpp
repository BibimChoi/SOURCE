// static_member
#include <iostream>

class RegisterShape
{
public:
	RegisterShape(int key)
	{
		std::cout << "Register Shape : " << key << std::endl;
	}
};

class Shape
{
public:
};
class Rect : public Shape
{
public:
	static RegisterShape rs;
};
RegisterShape Rect::rs(1);

class Circle : public Shape
{
public:
	static RegisterShape rs;
};
RegisterShape Circle::rs(2);

int main()
{
	// 이미 Rect, Circle 의 static 멤버 데이타인 rs 는 생성되어 있는 상태 입니다
	// rs의 생성자가 호출되는 것을 확인할수 있습니다.
}
