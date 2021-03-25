#include <iostream>
#include <functional> 

template<typename F, typename ... Ts>
decltype(auto) chronometry(F&& f, Ts&& ... args)
{
	return std::invoke(f, std::forward<Ts>(args)...);
}

struct Add
{
	int operator()(int a, int b) const &
	{
		std::cout << "lvalue °´Ã¼" << std::endl;
		return a + b;
	}

	int operator()(int a, int b) const &&
	{
		std::cout << "rvalue °´Ã¼" << std::endl;
		return a + b;
	}
};

int main()
{
	Add add;
	add(1, 2);

	Add()(1, 2);
}



