// nullptr.cpp

void foo(int* p) {}
void goo(char* p) {}

// nullptr �� ����
// 1. boost ���̺귯�� ������ �Ʒ� ó�� ���� ���
struct nullptr_t
{
	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ �Ͻ��� ��ȯ �ɶ� ȣ��.
	//				 Ư¡�� ���� Ÿ���� ǥ������ �ʽ��ϴ�.
	operator int*() const { return 0; }
};
nullptr_t xnullptr;

int main()
{
	foo(xnullptr);  // xnullptr => int* ���� �Ͻ��� ��ȯ �ʿ�
					// xnullptr.operator int*() ��� ��ȯ ������ �Լ� ȣ��
//	goo(xnullptr);
}
