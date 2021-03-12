// noexcept 이야기
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	// 핵심 : move 계열의 함수를 만들때
	// 되도록이면 예외가 없도록 구현하고.
	// 예외가 없다고 컴파일러에게 꼭알려 주세요
	Object(Object&&) noexcept   {	std::cout << "move" << std::endl;	}
};

int main()
{
	Object o1;
	Object o2 = o1;				// 무조건 복사 생성자 사용
	Object o3 = std::move(o2);	// 무조건 move 생성자 사용
	Object o4 = std::move_if_noexcept(o1); // move 생성자에 예외가 없다면 move사용
										   // 예외가 있을수 있으면 복사 생성자사용

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}




