
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
//	unique_ptr<int, [](void* p) {free(p); }  > up; // 람다표현식의 결과 => 객체

	// "람다표현식은 평가되지 않은 표현식안에는 넣을수 없다."
	// 단, C++20 부터는 넣을수 있다.
	unique_ptr<int, decltype([](void* p) {free(p); }) > up;

}