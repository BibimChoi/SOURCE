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
// Stream 에 압축기능을 제공하는 "Decorator"

class ZipDecorator : public Stream
{
	Stream* stream; // 외부에 있는 Stream(File, Network, Pipe)을 가리키는 포인터	
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void Write(const char* buff) override
	{
		std::string s = buff;
		s = s + " 압축됨";

		stream->Write( s.c_str() ); // Stream 이 가진 본래의 기능 사용
	}
};

class EncryptDecorator : public Stream
{
	Stream* stream; 
public:
	EncryptDecorator(Stream* s) : stream(s) {}

	void Write(const char* buff) override
	{
		std::string s = buff;
		s = s + " 암호화";

		stream->Write(s.c_str()); // Stream 이 가진 본래의 기능 사용
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");   

	ZipDecorator zd(&fs);	// 파일(fs)에 압축 기능 추가
	zd.Write("Hello");		
							

	EncryptDecorator ed(&zd); // 압축 기능이 추가된 객체에 다시 암호화 기능추가
	ed.Write("Hello");		
							
}

