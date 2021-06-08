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

}
