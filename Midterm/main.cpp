#include <iostream>

#include "Foo.h"
#include "Bar.h"

int main()
{
	Bar* b = new Bar();

	Foo* foo1 = reinterpret_cast<Foo*>(b);
	Foo* foo2 = static_cast<Foo*>(b);

	foo1->DoMagic();
	foo2->DoMagic();

	delete b;

	return 0;
}