﻿#include <iostream>

// Base-from-Member

class Buffer
{
	char* buff;
public:
	Buffer(int size) : buff(new char[size]) 
	{
		std::cout << "버퍼 크기 " << size  << "로 초기화" << std::endl;
	}
	void useBuffer() { std::cout << "버퍼 사용" << std::endl; }
};

class Stream
{
public:
	Stream(Buffer& buf) { buf.useBuffer();	}
};
//------------------------------------------
// 버퍼를 가진 PipeStream 설계
class PipeStream : public Stream
{
	Buffer buff{ 1024 }; 
public:
	PipeStream() : Stream(buff) {}
};

int main()
{
	PipeStream ps;

//	Buffer buff(1024);	// 1. 버퍼를 만들어서 
//	Stream stream(buff);// 2. Stream 에 전달..
}





