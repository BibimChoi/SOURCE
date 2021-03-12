#include <iostream>
#include <string>
#include <vector>

// 106 page

class Object {};

class Test
{
	Object data;
public:
	// setter 만들기
	//void setData(Object o) { data = o; } // call by value 는 좋지 않다


	// C++98 : const & 가 가장 좋다. ==> 가장 유명한 코딩 규칙
	//  단점 : move 를 지원할수 없는 setter
	// void setData(const Object& o) { data = o; }            // 항상 복사
	// void setData(const Object& o) { data = std::move(o); } // 항상 복사

	// 새로운 setter의 모양
	// 1. 2개 만들어라 - 107 page const 추가해 주세요
	//void setData(const Object& o) { data = o; }
	//void setData(Object&& o)      { data = std::move(o); }

	// 방법 2. call by value 가 아주 나쁜 것은 아니다.
	// 2개 만드는 것 보다는 오버헤드가 있지만, move 1회의 오버헤드이다.
	// move 가 충분히 빠른 타입이라면 아주 나쁘지는 않다.
//	void setData(Object o) { data = std::move(o); }
//	void setData(Object o) { data = o; } // 이렇게 만들면 복사 1회의 오버헤드

	// 방법 3. (1)번의 2개의 함수를 자동생성하자 - "T&&"
	// T&& : lvalue, rvalue를 모두 받겠다는 것 !=> 각 버전의 함수 생성
	template<typename T> void setData(T&& o)
	{
		// 다음중 맞는 것은 ?
		//data = o;				// 무조건 복사
		//data = std::move(o);	// 무조건 이동
		data = std::forward<T>(o); // lvalue가 도착하면 static_cast<Object&> => 복사
								   // rvalue가 도착하면 static_cast<Object&&> => move
	}
};


int main()
{
	Test test;
	Object o1;

	test.setData(o1);			 // o1 의 자원을 복사해라
							     // 복사 대입 1회
								 // 복사 1회, move 1회
	test.setData(std::move(o1)); // o1 의 자원을 가져가라(move)
								 // move 대입 1회
								 // move 2회
}








