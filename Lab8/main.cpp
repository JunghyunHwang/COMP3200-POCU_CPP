#include <cassert>
#include <iostream>
#include <chrono>
#include "Test.h"
#include <vector>

using namespace lab8;

int main()
{
	TestOfficial();
	TestWiki1();
	TestWiki2();
	MyTest();
	TestFixedBoolVector();
	
	std::cout << "No prob" << std::endl;

	system("pause");

	return 0;
}