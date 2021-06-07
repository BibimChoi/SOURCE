// Point.h
#pragma once

// 이 클래스가 Bridge 입니다.(사용자가 사용하는 추상계층)

class PointImpl; // 핵심.!!! 전방 선언만 있으면
				 // 포인터 변수 사용가능
				 // 핵심은 #include "PointImpl.h" 가 
				 // 필요 없다는것
class Point
{
	PointImpl* pImpl; // 구현이 있는 클래스를 가리키는 포인터
public:
	Point(int a, int b);
	void print();
};

// Point.cpp
#include "PointImpl.h"
#include "Point.h"

Point::Point(int a, int b) 
{
	pImpl = new PointImpl(a, b);
}
void Point::print() { pImpl->print(); }

// main.cpp
#include "Point.h"

int main()
{
	Point p(1, 2);
	p.print();
}

// PIMPL 이라는 이름을 가진 "C++ IDioms"
// "Pointer to IMPLementation"

// 컴파일러 방화벽이라고 불리기도 합니다.

// 장점
// 1. 실제 구현을 담은 클래스가 변해도(PointImpl)
//    사용하는 코드는 다시 컴파일 할 필요 없습니다.

// 2. 완벽한 코드 은닉
//    PointImpl.h 의 내용을 클라이언트에게 노출하지 않습니다.
