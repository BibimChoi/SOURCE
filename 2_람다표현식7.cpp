
template<typename T, typename D> class unique_ptr
{
public:
	~unique_ptr()
	{
		D d; 
		d(); 
	}
};
struct Freer
{
	void operator()(void* p) { free(p); }
};
int main()
{
//	unique_ptr<int, Freer> up;
//	unique_ptr<int, [](void* p) {free(p); }  > up; // ����ǥ������ ��� => ��ü

	// "����ǥ������ �򰡵��� ���� ǥ���ľȿ��� ������ ����."
	// ��, C++20 ���ʹ� ������ �ִ�.
	unique_ptr<int, decltype([](void* p) {free(p); }) > up;

}