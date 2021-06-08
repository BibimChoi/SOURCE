// static1.cpp
#include <iostream>

class RegisterShape
{
public:
	RegisterShape(int key) { std::cout << "RegisterShape : " << key << std::endl; }
};

class Shape {};

class Rect : public Shape
{
	static RegisterShape rs;
};
RegisterShape Rect::rs(1);

class Circle : public Shape
{
	static RegisterShape rs;
};
RegisterShape Circle::rs(2);

int main()
{
	// main 이 실행되기 전에. Rect/Circle의 rs는 이미 객체가 생성되었습니다.
	// 생성자에서 공장에 등록하므로 main 전에 도형이 공장에 등록되게 됩니다.
}
