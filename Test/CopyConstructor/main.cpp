#include <iostream>
#include "Point.h"
#include "Line.h"

int main()
{
	point::Point p1(0, 0);
	point::Point p2(2, 0);

	line::Line line1(p1, p2);
	line::Line line2(line1);

	std::cout << "No prob" << std::endl;

	return 0;
}