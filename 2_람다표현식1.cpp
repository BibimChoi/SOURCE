#include <algorithm>
#include <functional>  
#include <vector>
using namespace std;

// 람다 표현식의 원리

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//	std::sort(v.begin(), v.end(), 비교함수);

	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );
}






