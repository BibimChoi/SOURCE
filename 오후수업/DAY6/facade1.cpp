
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

// TCP Server 를 C언어로 구현한 코드 입니다.

// 특징 : C언어는 데이타와 함수가 분리되어 있어서 항상 복잡해 보입니다.

// 사용자가 사용하기 쉽게.. "데이타와 함수를 묶어서" 클래스로 제공해 봅시다.

// 다음중 좋은 것은 ?
// 1. 모든 기능을 하나의 클래스에!!
// 2. 각 기능별로 다른 클래스로 제공 => 좋은 코드

// 하나의 클래스는 하나의 책임만 
// : 단일 책임의 원칙(Single Responsibility Principle)


int main()
{
	// 1. 네트워크 라이브러리 초기화
	WSADATA w;
	WSAStartup(0x202, &w);

	// 2. 소켓 생성
	int sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓

	// 3. 소켓에 주소 지정
	struct sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	// 4. 소켓을 대기 상태로변경
	listen(sock, 5);

	// 5. 클라이언트가 접속할때 까지 대기
	struct sockaddr_in addr2 = { 0 };
	int sz = sizeof(addr2);

	accept(sock, (SOCKADDR*)&addr2, &sz);

	// 6. socket 라이브러리 cleanup
	WSACleanup();
}
