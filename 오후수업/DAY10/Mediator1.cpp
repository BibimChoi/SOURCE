// codexpert.org 에서 DAY10.zip 받으세요
// 소리 안들리시는 분은 다시 접속해 보세요..





#include <iostream>

// 객체간의 관계가 복잡하다면 "중재자"를 만들어라..!!

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	// 체크 상태가 변경되면 아래 가상함수 호출.
	virtual void ChangeState() {}
};

class MyCheckBox : public CheckBox
{
	RadioBox& radio;
public:
	MyCheckBox(RadioBox& r) : radio(r) {}

	void ChangeState() override
	{
		if (GetCheck() == true && radio.GetCheck() == true)
			std::cout << "enable 확인버튼" << std::endl;
		else 
			std::cout << "disable 확인버튼" << std::endl;
	}
};















class RadioBox
{
	bool state;
public:
	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

class MyRadioBox : public RadioBox
{
	CheckBox& check;
public:
	MyRadioBox(CheckBox& c) : check(c) {}

	void ChangeState() override
	{
		if (GetCheck() == true && check.GetCheck() == true)
			std::cout << "enable 버튼" << std::endl;
		else 
			std::cout << "disable 버튼" << std::endl;
	}
};



int main()
{
}



