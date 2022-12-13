#include <cassert>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "MyClass.h"

using namespace test;

constexpr int Factorial(const int n)
{
	return n <= 1 ? 1 : n * Factorial(n - 1);
}

int main()
{
	int value = 3;
	int result1 = Factorial(value);

	constexpr int result3 = Factorial(10); // OK
}