#include <iostream>
#include <string>
#include <string_view> // C++17

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << "bytes" << std::endl;
	return malloc(sz);
}

// ���ڿ��� �б⸸ �Ϸ��� string_view �� ����ض�!
//void foo(std::string s) // ���纻 ����
//void foo(std::string_view s) // ���� ���� ǥ���
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