// noexcept 이야기
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}

	// move 생성자가 예외가 발생하면 
	// 버퍼 이동시 중간에 예외 발생시 원본을 복구 할수 없습니다.

	// 핵심 : move 계열 함수를 만들때는 되도록 예외가 없도록 만들고..
	//        예외가 없음을 컴파일러에게 알려야 한다.

	Object(Object&&) noexcept  { std::cout << "move" << std::endl;	}
};

// 결론 : move 생성자를 직접 만들게 되면
//       꼭, 예외 없이 만들고, noexcept 붙이세요.
//       => 예외 발생가능성이 있는 함수를 호출하지 말라는것
//			ex) new int[100] => 이코드는 메모리 부족시 std::bad_alloc 예외 발생
int main()
{
	Object o1;
	Object o2 = o1; // 무조건 복사 생성자
	Object o3 = std::move(o2); // 무조건 move 생성자
	Object o4 = std::move_if_noexcept(o1); // move 생성자에 예외가 없으면 사용
									// 예외 가능성이 있으면 복사 생성자 사용



	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

