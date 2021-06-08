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
// 아래 처럼 만들면 Shape 안에 있는 static 멤버인 rs를
// 모든 도형이 공유 하게 됩니다.
// 도형마다 한개씩 있어야만 각 도형을 공장에 등록할수 있게 됩니다.
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

}
