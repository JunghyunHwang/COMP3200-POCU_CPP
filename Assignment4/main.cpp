#include <iostream>
#include <memory>

#include "Test.h"

using namespace assignment4;

int main()
{
	std::unique_ptr<int> num = std::make_unique<int>(3);

	std::cout << *num << std::endl;
	TestInsert();

	std::cout << "No prob" << std::endl;
	return 0;
}