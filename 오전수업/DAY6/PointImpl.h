#pragma once
//PointImpl.h

// 실제 구현을 가진 클래스
class PointImpl
{
	int x, y;
public:
	PointImpl(int a, int b);

	void print();
};

// PointImpl.cpp
#include <iostream>
#include "PointImpl.h"
using namespace std;


PointImpl::PointImpl(int a, int b) : x(a), y(b) {}

void PointImpl::print() 
{ 
	cout << x << ", " << y << endl; 
}










