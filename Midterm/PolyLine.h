#pragma once
#include "Point.h"
class PolyLine
{
public:
	PolyLine(Point p1, Point p2);
	PolyLine(const PolyLine& other);
	~PolyLine();

private:
	Point mP1;
	Point mP2;
};

