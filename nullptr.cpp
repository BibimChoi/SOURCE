// nullptr.cpp

void foo(int* p) {}
void goo(char* p) {}

// nullptr �� ����
struct nullptr_t
{
};
nullptr_t xnullptr;

int main()
{
	foo(xnullptr);
	goo(xnullptr);
}
