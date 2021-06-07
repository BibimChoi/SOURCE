#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const char* buff)
	{
		printf("%s 쓰기\n", buff);
	}
};
int main()
{
	// C++ 의 생성자/소멸자를 사용하면 안전하게 자원 관리할수 있습니다.
	// RAII ( Resource Acquision Is Initialization )
	// 자원을 획득하는 것은 (자원관리 객체가) 초기화 될때 이다.
	// 구글에서 "C++ IDioms" 라고 검색후 1번째 링크에 와보세요..

	// 디자인 패턴 : 언어에 무관한 객체지향 디자인 기술 ( 23가지 )
	// C++ IDioms : C++언어에서만 널리 사용되는 기술들 ( 널리 알려진것들이 100 여개 있습니다.)

	FileStream fs("a.txt");


	// C 언어의 문제점 : 항상 사용자가 직접 자원을 관리해야 한다.
//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);
}



