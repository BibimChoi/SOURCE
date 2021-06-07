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

	EncryptStream es(&fs);
	es.Write("Hello"); 

	ZipStream zs(&es);
	zs.Write("Hello"); 
}








