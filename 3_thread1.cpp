#include <iostream>
#include <thread> 

// this_thread namespace 

int main()
{
	int n = std::this_thread::get_id(); //현재 스레드 ID얻기
//	std::this_thread::sleep_for(3s);
}


