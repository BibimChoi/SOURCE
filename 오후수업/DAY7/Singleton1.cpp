// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.

// Meyer's 싱글톤 : 오직 한개의 객체를 static 지역변수로 만드는 모델
//					Effective-c++ 책의 저자인 scott-meyer 가 처음 제안한 모델
class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사와 대입 금지
	//		   컴파일러에게 복사 생성자와 대입연산자를 만들지 말라고 요청(함수 삭제)
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete; // 함수 삭제 라는 문법(C++11)

	// 규칙 3. 오직 한개의 객체만 만들어 반환 하는 static 함수
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

//	Cursor c3 = c1; // 이렇게 생성되는 것도 막아야 합니다.(복사 생성자)

//	Cursor c1, c2; // error. private 생성자
}








