// 자동 생성 규칙.
#include <iostream>
#include <string>

class Object
{
public:
	std::string name;
	Object() : name("kim") {}

	Object(const Object& obj) :name(obj.name) { std::cout << "copy" << std::endl; }
	Object& operator=(const Object& obj) { return *this; }

	Object(Object&&) = default;
	Object& operator=(Object&&) = default;
};

// 규칙 1. move 계열, 복사 계열을 모두 만들지 않으면
//      컴파일러가 모두 제공
//		컴파일러가 제공한 복사 : 모든 멤버 복사생성자 
//		컴파일러가 제공한 move : 모든 멤버 move생성자로

// 규칙 2. 사용자가 복사 계열만 제공했을때.
//     ==> move 계열함수는 자동 생성 안됨.
//     ==> std::move() 사용시 복사 계열 함수를 호출하게 됨.
//     이 경우.. move 계열이 필요 하면
//		A) 직접 만들거나
//      B) = default로 컴파일러에게 요청할수 있다 --핵심

// 규칙 3. move 계열만 제공하면
//     ==> 복사 계열 함수는 "삭제(delete)"된다.
//     ==> 복사가 필요한 코드가 있으면 컴파일 에러.

//		move 가 필요할때 복사 생성자를 사용할수 있지만
//      복사가 필요할때 move 생성자를 사용할수 없다.

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