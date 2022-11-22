#include <iostream>

#include <crtdbg.h>
#include "Test.h"

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

using namespace lab10;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TestOfficial();
	TestWiki();
	TestInsert();
	TestDelete();
	TestSearch();
	TestIndex();

	std::cout << "No prob" << std::endl;

	return 0;
}