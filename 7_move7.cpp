// git 에서 move7 번 다시 받아 보세요.
#include <iostream>
#include <string>

// 규칙 1. 복사 계열과 move 계열을 모두 만들지 않으면
//			컴파일러가 모두 제공해 준다. 
//			복사 계열 : 모든 멤버로 복사
//			move 계열 : 모든 멤버로 move

// 규칙 2. 사용자가 "복사계열" 만 제공할때 
//         컴파일러는 move 계열을 만들어 주지 않는다.
//			std::move() 사용시 사용자가 만든 "복사 생성자" 사용
//			move 기능을 지원너하려면
//			(A) move 생성자를 직접 만들거나
//			(B) = default 컴파일러에게 요청한다.
class Object
{
public:
	std::string name;
	Object(std::string name) : name(name) {}

	Object(const Object& obj) : name(obj.name)
	{
		std::cout << "사용자가 만든 복사 생성자" << std::endl;
	}

	Object(Object&&) = default; // 모든 멤버를 move로 옮기는 기본 버전을 제공해 달라


};

int main()
{
	Object o1("hello");
//	Object o2 = o1;
	Object o2 = std::move(o1);

	std::cout << o1.name << std::endl;
}


