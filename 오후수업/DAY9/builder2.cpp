// 2_Builder
#include <iostream>
#include <string>
using namespace std;

typedef string Hat;			// class Hat{}
typedef string Uniform;	    // class Uniform{}
typedef string Shoes;		// class Shoes{}
typedef string Character;	// class Character{}라고 가정

struct IBuilder
{
	virtual Hat     MakeHat() = 0;
	virtual Uniform MakeUniform() = 0;
	virtual Shoes   MakeShoes() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* pBuilder = nullptr;
public:
	void setBuilder(IBuilder* p) { pBuilder = p; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
		c = c + pBuilder->MakeHat();
		c = c + pBuilder->MakeUniform();
		c = c + pBuilder->MakeShoes();
		return c;
	}
};

class USA : public IBuilder
{
public:
	Hat     MakeHat()     override { return "야구모자 "; }
	Uniform MakeUniform() override { return "티셔츠 "; }
	Shoes   MakeShoes()   override { return "운동화"; }
};
class Korean : public IBuilder
{
public:
	Hat     MakeHat()     override { return "갓 "; }
	Uniform MakeUniform() override { return "한복 "; }
	Shoes   MakeShoes()   override { return "고무신"; }
};
int main()
{
	Korean k;
	Director d;
	d.setBuilder(&k); // <= 국가별 캐릭터 변경 버튼을 누르면 이곳을 수정.

	Character c = d.construct();
	cout << c << endl;

}



