#include <iostream>
#include <string>
#include <string_view> // C++17

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << "bytes" << std::endl;
	return malloc(sz);
}

// 문자열을 읽기만 하려면 string_view 를 사용해라!
//void foo(std::string s) // 복사본 생성
//void foo(std::string_view s) // 가장 좋은 표기법
void foo(const std::string& s)
{
}

int main()
{
	std::string s1 = "abcdefghijklmnopqrstrlksjflsjlsjflskf";

	foo(s1);

//	std::string s2 = s1;
//	std::string_view s3 = s1;
}