#include "cppmaster.h"
using namespace std;

class Data
{
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }
	Data(Data&& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(Data&&) { LOG_FUNCTION_NAME(); return *this; }
};

template<typename T> T&& xmove(T& obj)
{
	return static_cast<T&&>(obj);
}

Data foo()
{
	Data d;
	return d;
}

int main()
{
	Data d1;
		
	Data d2 = xmove(d1);
	Data d2 = xmove(foo());
	
}
