// 1_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

// Meyer's 의 싱글톤 : 오직 한개있는 객체가 static 지역변수로 있는 모델.
// effective-C++ 책의 저자인 "scott-meyer" 가 만들 모델

class Cursor
{
	// 규칙 1. 생성자를 private 에..
private:
	Cursor() {}

	// 규칙 2. 컴파일러에게 복사생성자와 대입연산자를 만들지 못하게 한다.
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};
int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
	std::cout << &c1 << ", " << &c2 << std::endl;

//	Cursor c3 = c2; // 이렇게 생성되는 객체도 막아야 한다.(복사 생성자도 막아야 한다.)

//	Cursor c1, c2; // error
}
