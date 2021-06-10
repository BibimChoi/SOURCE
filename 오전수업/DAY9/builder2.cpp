// 2_Builder
#include <iostream>
#include <string>
using namespace std;

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef string Hat;			// class Hat{}
typedef string Uniform;	    // class Uniform{}
typedef string Shoes;		// class Shoes{}
typedef string Character;	// class Character{}라고 가정

// 캐릭터를 만드는 각 공정의 결과는 교체 가능해야 합니다.
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
		// 캐릭터는 만드는 공정은 항상 동일 합니다.
		// 각, 과정의 결과는 다를수 있습니다.
		Character c;
		c = c + pBuilder->MakeHat();
		c = c + pBuilder->MakeUniform();
		c = c + pBuilder->MakeShoes();
		return c;
	}
};
// 각 국가별 캐릭터의 특징을 정의 하는 빌더들..
class USA : public IBuilder
{
public:
	Hat     MakeHat()     override { return "야구 모자"; }
	Uniform MakeUniform() override { return "운동복 "; }
	Shoes   MakeShoes()   override { return "운동화 "; }
};
class KOREAN : public IBuilder
{
public:
	Hat     MakeHat()     override { return "갓 "; }
	Uniform MakeUniform() override { return "한복 "; }
	Shoes   MakeShoes()   override { return "고무신 "; }
};

int main()
{
	Director d;
	USA b1;
	KOREAN b2;
	d.setBuilder(&b2); 
	Character c = d.construct();
	cout << c << endl;

}


