
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
	unique_ptr<int, Freer> up;

}