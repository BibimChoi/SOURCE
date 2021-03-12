#include <iostream>

// 일반 함수는 "동작"은 있지만 "상태"가 없다.

// 0 ~ 9 사이의 난수를 반환하는 함수
// "단, 중복되지 않은 값을 반환하게 변경해 보세요"
// 이전 값을 어딘가에 보관해야 합니다. ==> "어디?? 에 할까요 ?"
int urand()
{
	return rand() % 10;
}

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}





