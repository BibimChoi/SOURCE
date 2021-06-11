#include <iostream>
#include <algorithm>

template<typename Pred>
int* find_if(int* first, int* last, Pred f) 
{											
	while (first != last && f(*first) == false)
		++first;

	return first;
}
//--------------------------------
struct IsMod
{
	int value;
public:
	IsMod(int n) : value(n) {}

	inline bool operator()(int n) { return n % value == 0; }
};

int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int k;
	std::cin >> k;

	int* p1 = find_if(x, x + 10, [k](int n) {return n % k == 0; });

	// 위 한줄의 정확한 원리
	// 1. 람다표현식을 보고 컴파일러가 위에 있는 IsMod 같은 클래스를 생성합니다.
	// 2. 아래처럼 변경합니다.
	int* p2 = find_if(x, x + 10, IsMod(k)  ); // IsMod의 임시객체를 만드는 코드.

	std::cout << *p2 << std::endl;

	// 결론 : 람다 사용하세요... 그런데.. 람다의 원리가 IsMod입니다.
	//        find_if 같은 것 만들때 조건자를 템플릿으로 받으세요
}

