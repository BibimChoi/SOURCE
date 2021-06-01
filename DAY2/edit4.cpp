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

// 이제 다양한 종류의 Validator를 제공하면 됩니다.
class LimitDigitValidator : public IValidator
{
	int size;
public:
	LimitDigitValidator(int s) : size(s) {}

	bool validate(std::string s, char c) override 
	{
		return s.size() < size && isdigit(c);
	}
	bool iscomplete(std::string s) override
	{
		return s.size() == size;
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v);			// edit 에 값의 유효성을 조사하는 객체 연결
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


