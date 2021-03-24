#include <vector>
#include "cppmaster.h"
using namespace std;

class Data
{
	std::string name;
public:
	Data() = default;
	Data(const Data& d) { LOG_FUNCTION_NAME(); }
	Data& operator=(const Data&) { LOG_FUNCTION_NAME(); return *this; }


	// �Ʒ� move �����ڴ� ���ܰ� ������ ?

	Data(Data&& d) noexcept : name(std::move(d.name))  { }




	Data& operator=(Data&&) noexcept {  return *this; }
};








int main()
{
	Data d1;
	Data d2 = d1;// ������ ���� ������ ���
	Data d3 = std::move(d1); // ������ move ������ ���
	Data d4 = std::move_if_noexcept(d2);

	std::vector<Data> v(5);

	cout << "-----" << endl;

	v.resize(10); 

	cout << "-----" << endl;
}







