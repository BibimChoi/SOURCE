#include <vector>

int main()
{
	int n = 10;

	auto& a1 = n;   // ok
//	auto& a2 = 10;  // error

	// auto 는 템플릿과 동일 규칙
	// T&& 
	auto&& a3 = n; // int& a3 = n
	auto&& a4 = 10;// int&& a4 = 10
	// 핵심 : auto&& 는 rvalue reference 가 아니라 forwarding reference 입니다.

//	std::vector<int>  v1(10, 3);
	std::vector<bool> v2(10, false);
	
	auto& a = v1[0]; 

}




