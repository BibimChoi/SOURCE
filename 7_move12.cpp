#include "cppmaster.h"
#include <vector>
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
int main()
{
	Data d1;

	std::vector<Data> v;
	v.push_back(d1);
	v.push_back(std::move(d1));

}
