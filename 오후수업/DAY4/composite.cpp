// 4_Composite
#include <iostream>
#include <vector>
#include <string>


// File/Folder 클래스를 만들어 보세요 - 만들면,, Menu 와 동일한 구조가 됩니다.
// 공통의 부모 : Item
// 동일시 하는 함수는 뭘까요 ?

class Item
{
	std::string name;
public:
	Item(std::string s) : name(s) {}

	// 파일과 폴더 모두 크기를 구할수 있습니다.
	virtual int getSize() const = 0; // const 붙이세요
};

class File : public Item
{
	int size; // 파일은 자신의 크기가 있습니다
public:
	File(std::string s, int sz) : Item(s), size(sz) {}

	int getSize() const override { return size; } // 파일은 자신의 크기 반환
};

class Folder : public Item
{
	std::vector<Item*> v;
public:
	Folder(std::string s) : Item(s) {}

	void addItem(Item* p) { v.push_back(p); }

	int getSize() const override
	{
		int size = 0;
		for (auto p : v)
			size += p->getSize();

		return size;
	}
};








int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() << std::endl; // 20
	std::cout << fo1->getSize() << std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}



