#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	list<int> ss = { 1,2,3,4,5,1,2,3,4,5 };

	// 검색 : find는 전달된 반복자를 ++로 이동 합니다.
	auto ret1 = std::find(ss.begin(), ss.end(), 3); // 앞에서 부터 3찾기

//	auto ret2 = std::find(ss.end(), ss.begin(), 3); // 뒤에서 부터 3찾기 ?
									// 문제점 1. ss.end()는 마지막이 아닌 마지막 다음이다.
									// 2. ++했을때 거꾸로 동작해야 한다.





	auto p1 = std::make_reverse_iterator(ss.end());  // ss.end() -1로 초기화
	auto p2 = std::make_reverse_iterator(ss.begin());// ss.begin() -1로 초기화

	auto ret3 = std::find(p1, p2, 3); // ok~~


	auto ret4 = std::find(std::make_reverse_iterator(ss.end()), 
						  std::make_reverse_iterator(ss.begin()), 3);

	auto ret5 = std::find(ss.rbegin(), ss.rend(), 3); // 이 코드의 원리가 결국 
														// 윗줄입니다.

	// reverser iterator adapter 덕분에 모든 알고리즘은 뒤에서 부터도 할수 있습니다.
}








