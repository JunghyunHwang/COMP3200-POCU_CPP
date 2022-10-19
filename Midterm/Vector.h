#pragma once
class Vector
{
public:
	int mX;
	int mY;
};

Vector operator*(Vector& v, int x)
{
	Vector a;
	a.mX = v.mX * x;
	a.mY = v.mY * x;
	return a;
}

Vector operator/(Vector& v, int x)
{
	Vector a;
	a.mX = v.mX / x;
	a.mY = v.mY / x;
	return a;
}