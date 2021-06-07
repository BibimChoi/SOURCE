#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;



class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};
// IP 주소를 관리하는 클래스
class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

// Socket 작업을 책임지는 클래스
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};
//----------------------------------
// TCP 서버를 만들려면 몇개의 클래스를 가지고 몇가지의 과정을 거쳐야 합니다.

// FACADE 패턴 : 하위 시스템의 여러 절차를 단순화 하는 포괄적인 인터페이스를 가진
//			    상위 시스템을 제공하는 패턴.
//				복잡함을 단순화하는 패턴
class TCPServer
{
	NetworkInit init;
	Socket sock;
public:
	TCPServer() : sock(SOCK_STREAM) {}

	void Start(const char* sip, short port)
	{
		IPAddress addr(sip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};
int main()
{
	// 아래 코드가 최종 사용자 코드 입니다.
	TCPServer server;
	server.Start("127.0.0.1", 4000); // 사용하기가 정말 쉬워 졌습니다.

}
