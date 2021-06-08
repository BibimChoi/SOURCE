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
//----------------------------------------------------------
// 아래 코드는 static 멤버 데이타를 따로 물려 받기위해 템플릿을 사용하는 코드입니다.
template<int N> class Shape
{
public:
	static RegisterShape rs;
};
template<int N> RegisterShape Shape<N>::rs(N);

class Rect : public Shape<1>
{
public:
};

class Circle : public Shape<2>
{
public:
};

int main()
{
	// 아래 처럼 rs에 접근하는 코드가 있어야 rs가 생성됩니다.(템플릿의 지연된 인스턴스화 때문에)
	// 없으면 "지연된 인스턴스화" 때문에 rs가 생성되지 않습니다.
	RegisterShape& r1 = Rect::rs;
	RegisterShape& r2 = Circle::rs;
}
