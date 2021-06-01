#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 가상함수로 분리 - template method
// 2. 다른 클래스로 분리 - strategy

// 모든 Validator는 아래 인터페이스를 구현해야 한다.

struct IValidator
{
	virtual bool validate(std::string s, char c) = 0;
	virtual bool iscomplete(std::string s) { return true; }
	virtual ~IValidator() {}
};
// 주민 등록 번호 : 851   1   확인버튼

class Edit
{
	std::string data;
	
	IValidator* pVal = nullptr;
public:
	void setValidator(IValidator* p) { pVal = p; }

	std::string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (pVal == nullptr || pVal->iscomplete(data))   ) break;

			if ( pVal == nullptr || pVal->validate( data, c) ) // 값의 유효성 여부 확인을 외부에 위임
			{
				std::cout << c;
				data.push_back(c);
			}
		}
		std::cout << std::endl;

		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


