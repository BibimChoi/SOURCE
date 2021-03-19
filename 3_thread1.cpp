#include <iostream>
#include <thread>  // C++11
#include <chrono>
using namespace std::literals;

// this_thread namespace 

int main()
{
	int n = std::this_thread::get_id();

	std::this_thread::sleep_for(3s);
}


