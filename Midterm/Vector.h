#pragma once

#include <iostream>

class Vector
{
public:
	Vector(int x);
	virtual ~Vector();
	void Print() const;

private:
	int mX;
	int& mRef;
};