#include "Vector.h"

Vector::Vector(int x)
	: mX(x)
	, mRef(mX)
{
}

Vector::~Vector()
{
}

void Vector::Print() const
{
	std::cout << mRef << std::endl;
}