#include <cassert>
#include <iostream>
#include <vector>
#include <memory>
#include <map>

#include "MyClass.h"

using namespace test;

template<typename T>
constexpr T square(T a)
{
	return a * a;
}

int main()
{
	const int value = 3;
	constexpr int result = square<int>(value);
}