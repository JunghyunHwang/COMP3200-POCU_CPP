#pragma once

#include <cassert>
#include <memory>
#include <crtdbg.h>
#include <iostream>

#include "Node.h"
#include "DoubleLinkedList.h"

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#define malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

namespace lab10
{
	void TestOfficial();
	void TestWiki();
	void TestInsert();
	void TestDelete();
	void TestSearch();
	void TestIndex();
}