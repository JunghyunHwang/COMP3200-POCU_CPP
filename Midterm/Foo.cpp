#include "Foo.h"

unsigned int Foo::mCount = 0;

Foo::Foo(int x)
	: mX(x)
{
}

Foo::~Foo()
{
	++mCount;
}

Foo Foo::operator+(const Foo& f) const
{
	Foo x(*this);

	x.mX += f.mX;

	return x;
}

unsigned int Foo::GetCount()
{
	return mCount;
}