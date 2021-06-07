#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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
	//FileStream fs("a.txt");
	//	NetworkStream ns("127.0.0.1", 4000); // 네트워크에 쓰기
	//	PipeStream ps;	// IPC를 위해서 파이프에 쓰기

	// 파일 작업을 할때 데이타를 암호화 해서 기록해야 할 일이 생겼다.

	// 1. 별도로 데이타를 암호화 한후 파일에 쓴다
	//  => 이런 작업을 여러번 해야 한다면.. 

	// 2. FileStream 에 EncriptWrite() 함수를 추가한다.
	//  => fs.EncriptWrite("Hello")
	//  => NetworkStream 등 다른 stream 에도 추가해야 한다.

	// 3. 기반 클래스인 Stream 에 EncriptWrite() 함수를 추가한다.
	//  => 압축, XML, HTML 등으로 추가하는 기능도 필요 하면..
	//     Stream 클래스가 계속 변해야 한다. - OCP 만족할수 없다

	// 4. Decorator 패턴을 사용해서 "기능 추가 객체"를 만들면 OCP를 만족하게
	//    기능이 추가됩니다

	FileStream fs("a.txt");
	fs.Write("Hello");   // 그냥 파일에 쓰기

	EncryptStream es(&fs); // 데이타를 암호화해서 쓰는 기능 추가객체
	es.Write("Hello"); // 1. 데이타 암호화하는 기능 추가
						// 2. 자신이 보관중에 fs.Write()에 암호화된 데이타 전달

	ZipStream zs(&es);
	zs.Write("Hello"); // 1. "Hello" 를 압축하는 기능 추가
						// 2. 압축된 데이타를 es.Write() 에전달


}








