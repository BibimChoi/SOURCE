#include <iostream>
#include <string>
#include <string_view> // C++17

// ���ڿ��� �б⸸ �Ϸ��� string_view �� ����ض�!
void foo(std::string s)
{

}

int main()
{
	std::string s1 = "abcdefghijklmnopqrstrlksjflsjlsjflskf";
	std::string s2 = s1;

	std::string_view s3 = s1;

}