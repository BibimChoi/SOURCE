#include <iostream>
#include <string>
#include <conio.h>

// edit3.cpp

// 변하지 않은 흐름속에 있는 변해야 하는 코드는 분리되어야 한다.
// 방법 1. 변하는 것을 가상함수로 분리 한다.

class Edit
{
	std::string data;
public:

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

			if (validate(c)) // 값의 유효성 여부를 가상함수를 통해서 확인
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << std::endl;

		return data;
	}
};

// validation 정책을 변경하려면 Edit 파생 클래스를 만들어서
// 약속된 가상함수를 재정의 하면 된다.
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


