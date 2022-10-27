#include "Foo.h"

Foo::Foo()
	: mX(0)
{
}

Foo::~Foo() {}

void Foo::Print() const
{
	std::cout << "Foo" << std::endl;
}
