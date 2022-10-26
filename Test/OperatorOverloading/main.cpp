#include <cassert>
#include <iostream>
#include "Vector.h"

using namespace practice;

int main()
{
	Vector v1(0, 0);
	Vector v2(2, 1);

	Vector v3 = v1 + v2;
	Vector v4 = v1 * v2;
	assert(v1.GetX() == 0);
	assert(v1.GetY() == 0);
	assert(v2.GetX() == 2);
	assert(v2.GetY() == 1);
	assert(v3.GetX() == 2);
	assert(v3.GetY() == 1);
	assert(v4.GetX() == 0);
	assert(v4.GetY() == 0);

	++v1;
	assert(v1.GetX() == 1);
	assert(v1.GetY() == 1);

	Vector v5 = v1++;
	assert(v1.GetX() == 2);
	assert(v1.GetY() == 2);
	assert(v5.GetX() == 1);
	assert(v5.GetY() == 1);

	Vector v6 = 20 * v5;
	assert(v6.GetX() == 20);
	assert(v6.GetY() == 20);

	Vector v7 = --v6;
	assert(v7.GetX() == 19);
	assert(v7.GetY() == 19);

	Vector v8 = v7--;
	assert(v8.GetX() == 19);
	assert(v8.GetY() == 19);

	std::cout << "No prob" << std::endl;
	std::cout << sizeof(int) << std::endl;

	return 0;
}