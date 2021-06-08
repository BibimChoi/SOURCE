// codexpert.org에서 DAY7.zip 받으세요
// gibhub.com/codenuri/SOURCE    오후수업/DAY7/singleton1~2, helper.h 받아 두세요
// 싱글톤3.cpp 입니다.  1번 복사해 오세요.


#include <iostream>

// 싱글톤 패턴 : 객체를 오직 한개만 만들수 있게 하는 디자인 패턴.
class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}

	// 규칙 2. 복사생성자와 대입연산자를 삭제
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	// 규칙 3. 오직 한개만 만들어서 반환 하는 static 멤버 함수.
	// 오직 한개를 만드는 방법
	// 1. static 지역변수로!! - Singleton1.cpp 
	// 2. 힙에 new로 생성 - Singletone3.cpp(현재 소스)
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;
}








