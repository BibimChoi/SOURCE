#include <iostream>
#include <functional> 

template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return std::invoke(f, std::forward<Ts>(args)...);
}

struct Add
{
	int operator()(int a, int b) const
	{
		return a + b;
	}
};

int main()
{
	Add add;
	int n = add(1, 2); // add.operator()(1, 2)ÀÇ ¿ø¸®
}



