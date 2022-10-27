#include <cassert>
#include <iostream>
#include <iomanip>

#include "Base.h"
#include "A.h"

int main()
{
	Base* b = new A();
	b->baseMethod();

	delete b;

	return 0;
}