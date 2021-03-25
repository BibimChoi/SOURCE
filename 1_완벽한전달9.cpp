#include <iostream>
#include <functional> // std::invoke()

template<typename F, typename ... Ts>
decltype(auto) chronometry(F f, Ts&& ... args)
{
	return std::invoke(f, std::forward<Ts>(args)...);
}

int main()
{
	int n = add(1, 2);
}



