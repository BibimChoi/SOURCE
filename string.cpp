#include <iostream>
#include <string>
#include <string_view> // C++17

// 문자열을 읽기만 하려면 string_view 를 사용해라!
void foo(std::string s)
{

}

int main()
{
	std::string s1 = "abcdefghijklmnopqrstrlksjflsjlsjflskf";
	std::string s2 = s1;

	std::string_view s3 = s1;

}