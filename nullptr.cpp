// nullptr.cpp

void foo(int* p) {}
void goo(char* p) {}

// nullptr ÀÇ ¿ø¸®
struct nullptr_t
{
};
nullptr_t xnullptr;

int main()
{
	foo(xnullptr);
	goo(xnullptr);
}
