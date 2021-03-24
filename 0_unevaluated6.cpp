#include <iostream>

class Test
{
public:
	Test(int a) {}

	void resize() {}
};
// "Member Detect" 라는 C++ IDioms 입니다.

using YES = int[2];
using NO = int[1];

template<typename T> YES&  check(decltype(std::declval<T>().resize())* p);
template<typename T> NO&   check(...);

template<typename T> struct has_resize_function
{
	static constexpr bool value = (sizeof(check<T>(0)) == sizeof(YES));
};

int main()
{
	bool b = has_resize_function<Test>::value;

	std::cout << b << std::endl;
}



