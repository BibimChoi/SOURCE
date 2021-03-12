#include <iostream>
#include <bitset>   // STL 의 있는 "비트"를 관리하는 클래스

// 함수객체는 상태(멤버데이타)를 가질수 있다.!!!

class URandom
{
	// 멤버 데이타(상태보관)
	std::bitset<10> bs;
	bool recycle;
public:
	URandom(bool b = false) : recycle(b)
	{
		//bs.set(3); // 3번째 비트를 1로
		bs.set();  // 모든 비트를 1로
	}
	   

	int operator()()
	{
		if (bs.none()) // 모두 0
		{
			if (recycle == true)
				bs.set(); // 다시 모두 1로
			else
				return -1;
		}

		int k = -1;

		while ( !bs.test(k = rand() % 10) );

		bs.reset(k);

		return k;
	}





};

int main()
{
	//URandom urand;
	URandom urand(true);

	for (int i = 0; i < 15; i++)
		std::cout << urand() << std::endl;
}






