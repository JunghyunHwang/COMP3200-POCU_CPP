#include <iostream>
#include "Test.h"

using namespace lab5;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TestOfficial();
	TestWiki1();
	TestWiki2();
	TestLawnArea();

	std::cout << "No prob" << std::endl;
	return 0;
}