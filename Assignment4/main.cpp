#include <iostream>
#include <memory>

#include "Test.h"

using namespace assignment4;

int main()
{
	TestOfficial();
	TestInsert();
	TestSearch();
	TestNormalTree();
	TestOnlyLeftTree();
	TestOnlyRightTree();

	std::cout << "No prob" << std::endl;
	return 0;
}