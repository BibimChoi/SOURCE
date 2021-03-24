// 7_move13

template<typename T, typename U> struct PAIR
{
	T first;
	U second;

	PAIR(const T& a, const T& b) : first(a), second(b) {}
};
int main()
{
	std::string s1 = "AAA";
	std::string s2 = "CCCC";
	PAIR<std::string, std::string> p1(s1, s2);
}