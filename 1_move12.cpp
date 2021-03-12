// 자동 생성 규칙.
#include <iostream>
#include <string>

class Object
{
public:
	std::string name;
	Object() : name("kim") {}

	Object(const Object& o) : name(o.name) { std::cout << "copy" << std::endl; }
	Object& operator=(const Object& o)    { return *this; }

	// 컴파일러에게 move 계열 함수의 디폴트 구현을 요청한다.
	Object(Object&&) = default;
	Object& operator=(Object&&) = default;
};

// 규칙 1. 복사 계열과 move 계열을 모두 만들지 않으면
//         컴파일러가 모두 만들어 준다.

// 규칙 2. 복사 계열만 제공하면 move계열은 자동생성 안됨.
//        std::move() 사용시 "복사 계열 함수 호출"
//        이때 move계열함수 가 필요하면
//		  (A) 직접 move 계열 함수를 만들거나
//        (B) = default 로 컴파일러에게 요청

// 규칙 3. Move 계열만 제공하면
//		   복사 계열 함수는 "삭제(delete)" 된다.
//		   복사 가 필요 한 코드는 모두 컴파일 에러
//		(A) 사용자가 복사 계열을 만들거나
//      (B) 컴파일러에게 요청할수 있다.

int main()
{
	Object o1;
	Object o2 = o1;
	o2 = o1;
	std::cout << o1.name << std::endl;

	Object o3 = std::move(o1);
	o3 = std::move(o2);

	std::cout << o1.name << std::endl;
}