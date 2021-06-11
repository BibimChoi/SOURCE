#include <iostream>
#include <algorithm>

// 일반 함수 : 동작은 있는데,, 상태가 없다..
// 객체      : 상태와 동작을 모두 가질수 있다. 멤버 데이타가 있다는 의미

// C#에서 사용하는 기술..
// 모든 조건자는 아래 인터페이스를 구현해야 한다.
struct IPredicator
{
	virtual bool valid(int n) = 0;
	virtual ~IPredicator() {}
};

// 마지막 인자로 "조건자 함수"가 아닌 "조건자 객체" 를 전달 받습니다.
int* find_if(int* first, int* last, IPredicator* pred)
{
	while (first != last && pred->valid(*first) == false)
		++first;

	return first;
}

// 특정 숫자의 배수를 찾는 조건자 객체
// 함수가 아닌 객체는 상태(멤버 데이타)를 가질수 있습니다.
struct IsMod : public IPredicator
{
	int value; 
public:
	IsMod(int n) : value(n) {}

	bool valid(int n) override{ return n % value == 0; }
};

bool foo(int n) { return n % 3 == 0; }



int main()
{
	int x[10] = { 1,2,6,7,8,3,4,5,9, 10 };

	int k;
	std::cin >> k;
	
	IsMod f(k); // 조건자 "객체" - 객체 이므로 상태를 가질수 있습니다.
	int* p = find_if(x, x + 10, &f);

	std::cout << *p << std::endl;
}
