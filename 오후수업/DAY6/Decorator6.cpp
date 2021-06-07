#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


// 모든 종류의 Stream 은 아래 인터페이스를 구현해야 한다.
struct Stream
{
	virtual void Write(const char* buff) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
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
	//  FileStream fs("a.txt");
	//	NetworkStream ns("127.0.0.1", 4000); // N/W로 쓰기
	//	PipeStream ps; // IPC를 위해 파이프에 쓰기

	// 파일에 쓸때 데이타를 압축해서 쓰고 싶다.
	// 방법 1. 데이타를 압축후에 fs.Write()...
	//			=> 이런 작업을 여러번 해야 한다면...

	// 방법 2. fs.ZipWrite() 라는 멤버 함수를 FileStream 에 추가
	//			=> NetworkStream 등 모든 Stream 에도 필요 하다.

	// 방법 3. 기반 클래스인 Stream 에 ZipWrite() 함수 추가
	//			=> 암호화해서 쓰기, XML로 쓰기등의 요구사항이 생길때마다 
	//				기존 클래스 코드 수정. OCP위반

	// 방법 4. Decorator 패턴을 사용하면 OCP를 만족하면서 기능을 추가할수 있다.
	FileStream fs("a.txt");
	fs.Write("Hello");   // 그냥 파일에 기록

	ZipDecorator zd(&fs);	// 파일에 압축기능을 추가하는 데코레이터
	zd.Write("Hello");		// 1. "Hello"를 압축후에..
							// 2. fs.Write(압축된데이타) => 원래 기능 수행

	EncryptDecorator ed(&zd);
	ed.Write("Hello");		// 1. 암호화
							// 2. zd.Write(암호화데이타)
}














