#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> up1(new int);
	//std::unique_ptr<int> up2 = up1; // error
	std::unique_ptr<int> up3 = std::move(up1); // ok..

	// ������ ������ ��� ������
	std::shared_ptr<int> sp(new int);
	std::unique_ptr<int> up(new int);

	std::shared_ptr<int> sp1 = up;				// 1. error
	std::shared_ptr<int> sp2 = std::move(up);	// 2. ok

	std::unique_ptr<int> up1 = sp;				// 3. error
	std::unique_ptr<int> up2 = std::move(sp);	// 4. error
}

// �Ʒ� �ڵ忡�� ��ȯ Ÿ���� ����Ʈ �����ͷ� �����Ϸ��� �մϴ�.
// shared vs unique �� ������ ������
// shared_ptr �� ��ȯ�ϸ� : shared_ptr �θ� ������ �ֽ��ϴ�.
// unique_ptr �� ��ȯ�ϸ� : �޴� �ʿ��� shared_ptr, unique_ptr�� �����Ҽ� �ֽ��ϴ�.
//						    ��ȯ ��ü�� "unique_ptr"�� �ӽð�ü��� ���� �ٽ�.
//std::shared_ptr<int> Alloc(int sz)
std::unique_ptr<int> Alloc(int sz)
{
	return static_cast<int*>(malloc(sz));
}

std::shared_ptr<int> ret1 = Alloc(100);
std::unique_ptr<int> ret2 = Alloc(100); // shared ���� �ϸ� ����





