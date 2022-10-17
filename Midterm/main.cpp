#include <iostream>

#include "Point.h"
#include "PolyLine.h"

int main()
{
	Point p1(-2, 3);
	Point p2(3, 7);

	PolyLine pl1(p1, p2);
	PolyLine pl2(pl1);

	std::cout << Point::mCount << std::endl; // 4

	return 0;
}