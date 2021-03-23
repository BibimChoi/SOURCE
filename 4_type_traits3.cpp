#include <iostream>
template<typename T> struct is_pointer
{
	static constexpr bool value = false;
};
template<typename T> struct is_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	if (is_array<T>::value) 
		std::cout << "배열" << std::endl;
	else
		std::cout << "배열 아님" << std::endl;
}
int main()
{
	int x[3] = { 1,2,3 };
	foo(x);
}
// is_pointer 변경해서 is_array 만들어 보세요