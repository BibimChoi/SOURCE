#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// 변하지 않은 흐름속에 있는 변하는 것은 분리되어야 한다.

	// 방법 1. 변하는 것을 가상함수로 분리한다
	virtual bool validate(char c)
	{
		return true;
	}
	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break;

			if (validate(c)) // <<=== 값의 유효성 확인을 위해 가상함수 호출
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << std::endl;  // <=== std:: 추가해 주세요.

		return data;
	}
};
//------------------
// 이제 Edit 의 유효성 정책을 변경하려면 파생 클래스를 만들어서
// 약속된 가상함수를 재정의 하면 됩니다

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);  
	}
};

int main()
{
	NumEdit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}








