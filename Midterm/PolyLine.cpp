#include "PolyLine.h"

PolyLine::PolyLine(Point p1, Point p2)
	: mP1(p1)
	, mP2(p2)
{
}

PolyLine::PolyLine(const PolyLine& other)
	: mP1(other.mP1)
	, mP2(other.mP2)
{
}

PolyLine::~PolyLine()
{
}
