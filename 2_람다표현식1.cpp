#include <algorithm>
#include <functional>  
#include <vector>
using namespace std;

// 람다 표현식의 원리

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//	std::sort(v.begin(), v.end(), 비교함수 또는 함수 객체);

	// C++11 부터는 람다 표현식 사용
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; } );

	//----------------------------------
	// 위 코드를 보고 컴파일러가 아래 클래스를 생성합니다
	class ClosureType
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}
		//..... 
	};
	// 결국 람다표현식을 사용하는 코드는 아래와 같이 "함수객체를 임시객체형태로전달"
	// 하는 코드입니다.
	std::sort(v.begin(), v.end(), ClosureType() );
}






