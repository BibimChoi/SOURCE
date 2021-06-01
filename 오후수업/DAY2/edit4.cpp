#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로!!
// 2. 변하는 것을 다른 클래스

// 모든 Validator는 아래 인터페이스를 구현해야 한다
struct IValidator
{
	virtual bool validate(std::string s, char c) = 0;

	virtual bool iscomplete(std::string s) { return true; }

	virtual ~IValidator() {}
};

// 주민 등록 번호 : 851  1   확인버튼

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

			if (c == 13 && (pVal == nullptr || pVal->iscomplete(data) )  ) break;

			if ( pVal == nullptr || pVal->validate(data, c) ) // 값의 유효성 여부를
			{												  // 외부 객체에 위임
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

	LimitDigitValidator v(5); // 값의 유효성을 확인하는 객체를 생성후
	e.setValidator(&v);       // edit 와 연결

	LimitDigitValidator v2(15);
	e.setValidator(&v2);       

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}
// 핵심 정리 : 변하지 않은 흐름속에 변하는 것은 분리하세요
//			   (공통성과 가변성을 분리)

// 1. 변하는 것을 가상함수로 분리 => 실행시간 교체는 불가능하고, 정책의 재사용성도 힘듬..

// 2. 변하는 것을 다른 클래스로 분리 => 실행시간 교체가능, 정책을 다른 클래스에서 사용가능

// Edit3.cpp 에서
//NumEdit e1;
//AddressEdit e2; // e1이 정책을 변경한것이 아니라.. 다른 정책을 가진 다른 editbox
				// 즉, 2개의 edit 박스
				// 다른 정책을 가진 또다른 Edit를 "코딩시간"에 만들어서 사용하는 것
// Edit4.cpp
//Edit e;
//e.setValidator(&v1);
//e.setValidator(&v2); // 같은 editbox를 실행시간에 정책만 교체해서 사용

