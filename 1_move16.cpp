#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string s1 = "ABC";

	std::vector<std::string> v;

	// push 보다 emplace가 좋다
	v.emplace_back("DEF"); 

	// 기존에 사용하던 객체를 넣을때는 push를 사용해도 된다..
	v.push_back(s1);		// 자원을 복사해 가라... 즉, s1은 계속사용
	std::cout << s1 << std::endl; // "ABC"

	v.push_back(std::move(s1)); // 자원을 가져가라.. 즉, s1은 더이상 자원없음
	std::cout << s1 << std::endl; // ""
}



