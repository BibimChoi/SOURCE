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
// Stream 에 기능을 추가하는 객체
class EncryptStream : public Stream
{
	Stream* stream;
public:
	EncryptStream(Stream* s) : stream(s) {}

	void Write(const char* s) override
	{
		// 기능을 추가후
		std::string str = s;
		str = str + " 암호화";

		// 원래 객체에 전달
		stream->Write( str.c_str() ); // 객체의 원래 기능 사용
	}
};

class ZipStream : public Stream
{
	Stream* stream;
public:
	ZipStream(Stream* s) : stream(s) {}

	void Write(const char* s) override
	{
		// 기능을 추가후
		std::string str = s;
		str = str + " 압축";

		// 원래 객체에 전달
		stream->Write(str.c_str()); // 객체의 원래 기능 사용
	}
};
int main()
{
	FileStream fs("a.txt");
	fs.Write("Hello");   

//	XmlStream xs(&fs);
//	xs.Write("Hello");  // "Hello" 앞뒤에 XML Tag 를 추가해서 쓴다

	EncryptStream es(&fs);
	es.Write("Hello"); 

	ZipStream zs(&es);
	zs.Write("Hello"); 

	// 새로운 기능 추가가 필요하면
	// 새로운 Decorator만 만들면 됩니다
}

// C# 언어가 위 처럼 "Decorator"패턴으로 되어 있습니다.

// 저장소				Decorator
// FileStream			EncryptStream
// PipeStream			GZipStream
// NetworkStream		XmlStream 
//						HtmlStream






