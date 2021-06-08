// static1.cpp
#include <iostream>

class RegisterShape
{
public:
	RegisterShape(int key) { std::cout << "RegisterShape : " << key << std::endl; }
};

// 핵심 : 기반 클래스의 static 멤버 데이타는 모든 파생클래스가 공유(오직한개를) 하게 됩니다.
class Shape 
{
	static RegisterShape rs;
};
RegisterShape Shape::rs(1);

class Rect : public Shape
{

};
class Circle : public Shape
{
};

int main()
{

}
