#include <vector>

int main()
{
	Vector<int>  v1(10, 3);
	Vector<bool> v2(10, false);

	auto& r1 = v1[0]; // ok.    v1[0] �� �ӽð�ü �ƴ�.
	auto& r2 = v2[0]; // error. v2[0] �� �ӽð�ü ��ȯ.
}




