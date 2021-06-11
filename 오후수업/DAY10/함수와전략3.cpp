#include <iostream>
#include <algorithm>

// C# 의 해결책 : 조건자를 "함수"로 하지말고 "객체"로 하면 어떨까 ?

// 검색에 사용하는 모든 조건자 객체를 아래 인터페이스를 구현해야 한다.

struct IPredicator
{
	virtual bool valid(int n) = 0;
	virtual ~IPredicator() {}
};
// 함수 포인터가 아닌 인터페이스로 전달 받는다.
int* find_if(int* first, int* last, IPredicator* pred)
{
	while (first != last && pred->valid(*first) == false)
		++first;

	return first;
}

bool foo(int n) { return n % 3 == 0; }

//-----------------------
// find_if 에 보낼 조건자 객체를 만든다.
struct IsMod : public IPredicator
{
	int value;  // 조건자 함수는 상태가 없지만
				// 조건자 객체는 상태를 가질수 있습니다.(멤버 데이타가 있다는 의미)
public:
	IsMod(int n) : value(n) {} 

	bool valid(int n) override { return n % value == 0;  } 
};

int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int k;
	std::cin >> k;

	// 사용자가 입력한 k의 배수를 찾고 싶다면 ???
	IsMod pred(k);

	int* p = find_if(x, x + 10, &pred); 

	std::cout << *p << std::endl;
}
