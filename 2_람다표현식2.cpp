#include <algorithm>
#include <functional>  
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;

	// 람다표현식은 auto 변수에 담아서 함수 처럼 사용해도 됩니다.
	auto f = [](int a, int b) {return a + b; };
			// class xxxx{}; xxxx();


	int n = f(1, 2); // f.operator()(1,2),그리고, 인라인 치환됨.

	// 지역변수 캡쳐 : 람다표현식에서 지역변수에 접근하기 위해 사용
	//auto f2 = [v1, v2](int a) { return a + v1 + v2; };

	auto f2 = ClosureType(v1, v2);
}

class ClosureType
{
	int v1;
	int v2;
public:
	ClosureType(int v1, int v2) : v1(v1), v2(v2) {}

	inline int operator()(int a) const
	{
		return a + v1 + v2;
	}
};





