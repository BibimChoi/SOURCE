// static1.cpp
#include <iostream>

class RegisterShape
{
public:
	RegisterShape(int key) { std::cout << "RegisterShape : " << key << std::endl; }
};

//-----------------------------------------------------
template<int N>
class Shape
{
public:
	static RegisterShape rs;
};
template<int N> RegisterShape Shape<N>::rs(N);

class Rect : public Shape<1>
{
};
class Circle : public Shape<2>
{
};

int main()
{
	// 아래 처럼 하면 rs가 사용되었으므로 main 함수 이전에 rs의 생성자 호출됩니다.
	// 아래 코드가 없으면 rs는 인스턴스화 안되므로 생성자 호출안됩니다.
	RegisterShape& r1 = Rect::rs;
	RegisterShape& r2 = Circle::rs;
}



