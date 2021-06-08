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

}



