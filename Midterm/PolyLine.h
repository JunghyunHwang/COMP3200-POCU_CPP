#pragma once

#include "Point.h"

class PolyLine
{
public:
	~PolyLine();
	Point GetP1() const;
	Point GetP2() const;

private:
	Point mP1;
	Point mP2;
};

