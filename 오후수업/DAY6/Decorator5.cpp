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
	FileStream fs("a.txt");
//	NetworkStream ns("127.0.0.1", 4000); // N/W로 쓰기
//	PipeStream ps; // IPC를 위해 파이프에 쓰기
}



