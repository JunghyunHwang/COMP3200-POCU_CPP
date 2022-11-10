#include <cassert>
#include <iostream>
#include <chrono>
#include "Test.h"
#include <vector>

using namespace lab8;

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	MyTest();
	TestFixedBoolVector();

	auto end = std::chrono::high_resolution_clock::now();

	auto elapseNanoSecond = end - start;

	std::cout << elapseNanoSecond.count() << std::endl;

	std::cout << "No prob" << std::endl;

	system("pause");

	return 0;
}