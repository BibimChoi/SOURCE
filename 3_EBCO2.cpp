#include <iostream>

class Empty
{
};

/*
struct Data
{
	Empty e; // 1
	int   n; // 4
};
*/

/*
#pragma pack(1)		// 구조체 정렬(align)을 1byte 단위로
struct Data
{
	Empty e; // 1
	int   n; // 4
};
*/
// Empty 로 부터 상속 받으면 Empty 의 크기가 1이 아닌 0으로 계산된다.
// Empty Base Class Optimization : EBCO 라고 합니다.
struct Data : Empty
{
	int   n; // 4
};


int main()
{
	Data d;
	std::cout << sizeof(d) << std::endl; 
}





