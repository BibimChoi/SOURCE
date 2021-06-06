#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 모든 Stream 이 지켜야 하는 규칙을 설계 한다.
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

//	NetworkStream ns("127.0.0.1", 4000); // 네트워크에 쓰기

//	PipeStream ps;	// IPC를 위해서 파이프에 쓰기
}



