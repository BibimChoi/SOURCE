// 10_concept3
#include <iostream>
#include <vector>

template<typename Iter> 
void sort(Iter first, Iter last)
{
	std::cout << "sort 기본 버전" << std::endl;
}
template<typename Iter, typename Pred>
void sort(Iter first, Iter last, Pred f)
{
	std::cout << "sort 조건자를 받는 버전" << std::endl;
}
 
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	sort(v.begin(), v.end()); // 만들어 봅시다.

	// 비교정책을 교체 가능하게 설계하자.
	sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );
}