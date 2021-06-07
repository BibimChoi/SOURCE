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

	// 3을 검색
	auto ret1 = std::find(ss.begin(), ss.end(), 3); // 앞에서 부터 순차 검색

	// 뒤에서 부터 검색하려면
//	auto ret2 = std::find(ss.end(), ss.begin(), 3); // error. 
											// 1.end()는 마지막이아닌 마지막 다음 요소
											// 2. find는 ++ 로 이동하므로 거꾸로 동작..

	auto ret2 = std::find(std::make_reverse_iterator(ss.end()), // ss.end()-1로 초기화,
																// ++연산시 --로 동작
						  std::make_reverse_iterator(ss.begin()), 3);

	// 아래와 같은 rbegin()/rend()의 원리가 위 코드 입니다.
	auto ret3 = std::find(ss.rbegin(), ss.rend(), 3);
}







