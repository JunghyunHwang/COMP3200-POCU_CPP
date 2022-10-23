#pragma once

#include <iostream>

class Vector
{
public:
	Vector(int x, int y);
	virtual ~Vector();
	Vector& operator=(const Vector& rhs);

private:
	int mX;
	int mY;
};